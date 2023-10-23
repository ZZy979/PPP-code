#include <algorithm>
#include <iostream>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include "email_message.h"

using namespace std;

void print_usage(const char* prog);

using Options = unordered_map<string, string>;
bool parse_args(int argc, char* argv[], Options& options, string& filename);

vector<Message> find_by_sender_addr(const vector<Message>& messages, const string& addr);
vector<Message> find_by_sender_name(const vector<Message>& messages, const string& name);
vector<Message> find_by_recipient_addr(const vector<Message>& messages, const string& addr);
vector<Message> find_by_recipient_name(const vector<Message>& messages, const string& name);
vector<Message> find_by_subject(const vector<Message>& messages, const string& subject);

/**
 * Find all email messages that meet user-specified criteria through command-line arguments and print their "Subject".
 *
 * Command-line arguments:
 * * -sa: sender address
 * * -sn: sender name
 * * -ra: recipient address
 * * -rn: recipient name
 * * -s: subject
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 0;
    }

    Options options;
    string filename;
    if (!parse_args(argc, argv, options, filename)) {
        print_usage(argv[0]);
        return 1;
    }

    Mail_file mfile(filename);
    vector<Message> messages(mfile.begin(), mfile.end());

    using FilterFunc = function<vector<Message>(const vector<Message>&, const string&)>;
    unordered_map<string, FilterFunc> filters = {
        {"-sa", find_by_sender_addr},
        {"-sn", find_by_sender_name},
        {"-ra", find_by_recipient_addr},
        {"-rn", find_by_recipient_name},
        {"-s", find_by_subject}
    };
    for (const auto& p : filters)
        if (!options[p.first].empty())
            messages = p.second(messages, options[p.first]);

    for (const Message& m : messages)
        cout << get_subject(m) << '\n';
    return 0;
}

void print_usage(const char* prog) {
    cout << "Usage: " << prog << " [-sa <sender_address>] [-sn <sender_name>]"
            << " [-ra <recipient_address>] [-rn <recipient_name>] [-s <subject>] filename";
}

bool parse_args(int argc, char* argv[], Options& options, string& filename) {
    int i = 1;

    while (i < argc && argv[i][0] == '-') {
        if (i < argc - 1) {
            options[argv[i]] = argv[i + 1];
            i += 2;
        }
        else {
            cerr << "error: option " << argv[i] << " has no value\n";
            return false;
        }
    }

    if (i == argc) {
        cerr << "error: no filename argument\n";
        return false;
    }

    filename = argv[i];
    return true;
}

vector<Message> filter(const vector<Message>& messages, const function<bool(const Message&)>& filter) {
    vector<Message> result;
    copy_if(messages.begin(), messages.end(), back_inserter(result), filter);
    return result;
}


vector<Message> find_by_sender_addr(const vector<Message>& messages, const string& addr) {
    return filter(messages, [&addr](const Message& m) { return has_sender_addr(m, addr); });
}
vector<Message> find_by_sender_name(const vector<Message>& messages, const string& name) {
    return filter(messages, [&name](const Message& m) { return has_sender_name(m, name); });
}

vector<Message> find_by_recipient_addr(const vector<Message>& messages, const string& addr) {
    return filter(messages, [&addr](const Message& m) { return has_recipient_addr(m, addr); });
}

vector<Message> find_by_recipient_name(const vector<Message>& messages, const string& name) {
    return filter(messages, [&name](const Message& m) { return has_recipient_name(m, name); });
}

vector<Message> find_by_subject(const vector<Message>& messages, const string& subject) {
    return filter(messages, [&subject](const Message& m) { return contains_subject(m, subject); });
}
