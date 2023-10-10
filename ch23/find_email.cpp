#include <iostream>
#include <map>

#include "email_message.h"

using namespace std;

// Find all email messages by sender and print their "Subject".
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " filename sender\n";
        return 0;
    }

    Mail_file mfile(argv[1]);   // initialize mfile from a file

    // first gather messages from each sender together in a multimap:
    multimap<string, const Message*> sender;

    for (const auto& m : mfile) {
        string s;
        if (find_from_addr(m, s))
            sender.insert(make_pair(s, &m));
    }

    // now iterate through the multimap and extract the subjects of given sender's messages:
    auto pp = sender.equal_range(argv[2]);
    for (auto p = pp.first; p != pp.second; ++p)
        cout << find_subject(*p->second) << '\n';
    return 0;
}
