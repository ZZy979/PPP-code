#include "email_message.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>

// open file, read the lines into `lines`,
// find the messages in the lines and compose them in `m`
// for simplicity assume every message is ended by a "----" line
Mail_file::Mail_file(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "can't open " << filename << '\n';
        throw std::runtime_error("can't open " + filename);
    }

    // build the vector of lines
    for (std::string s; std::getline(in, s);)
        lines.push_back(s);

    // build the vector of Messages
    auto first = lines.begin();
    for (auto p = lines.begin(); p != lines.end(); ++p) {
        if (*p == "----") {     // end of message
            m.emplace_back(first, p);
            first = p + 1;      // "----" is not part of message
        }
    }
}

// is p the first part of s?
int is_prefix(const std::string& s, const std::string& p) {
    int n = p.size();
    return s.substr(0, n) == p ? n : 0;
}

// find the address of the sender in a Message;
// if found, place the sender's name in s and return true
bool find_from_addr(const Message& m, std::string& s) {
    for (const auto& line : m)
        if (int n = is_prefix(line, "From: ")) {
            s = line.substr(n);
            return true;
        }
    return false;
}

// return the subject of the Message, if any, otherwise ""
std::string find_subject(const Message& m) {
    for (const auto& line : m)
        if (int n = is_prefix(line, "Subject: "))
            return line.substr(n);
    return "";
}

std::string get_header(const Message& m, const std::string& header) {
    std::regex pat(header + ": (.+)");
    std::smatch match;
    for (const std::string& line : m)
        if (std::regex_match(line, match, pat))
            return match.str(1);
    return "";
}

std::string get_sender(const Message& m) {
    return get_header(m, "From");
}

std::string get_recipient(const Message& m) {
    return get_header(m, "To");
}

std::string get_subject(const Message& m) {
    return get_header(m, "Subject");
}

static const std::regex ADDR_PATTERN(R"(([\w ]+) <(\w+@\w+\.\w+)>)");

bool has_sender_addr(const Message& m, const std::string& addr) {
    std::string sender = get_sender(m);
    return std::any_of(std::sregex_iterator(sender.begin(), sender.end(), ADDR_PATTERN), std::sregex_iterator(),
            [&addr](const std::smatch& match) { return match.str(2) == addr; });
}

bool has_sender_name(const Message& m, const std::string& name) {
    std::string sender = get_sender(m);
    return std::any_of(std::sregex_iterator(sender.begin(), sender.end(), ADDR_PATTERN), std::sregex_iterator(),
            [&name](const std::smatch& match) { return match.str(1) == name; });
}

bool has_recipient_addr(const Message& m, const std::string& addr) {
    std::string sender = get_recipient(m);
    return std::any_of(std::sregex_iterator(sender.begin(), sender.end(), ADDR_PATTERN), std::sregex_iterator(),
            [&addr](const std::smatch& match) { return match.str(2) == addr; });
}

bool has_recipient_name(const Message& m, const std::string& name) {
    std::string sender = get_recipient(m);
    return std::any_of(std::sregex_iterator(sender.begin(), sender.end(), ADDR_PATTERN), std::sregex_iterator(),
            [&name](const std::smatch& match) { return match.str(1) == name; });
}

bool contains_subject(const Message& m, const std::string& subject) {
    return get_subject(m).find(subject) != std::string::npos;
}
