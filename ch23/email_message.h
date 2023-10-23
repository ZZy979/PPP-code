#pragma once

#include <string>
#include <vector>

using Line_iter = std::vector<std::string>::const_iterator;

// a Message points to the first and the last lines of a message
class Message {
public:
    Message(Line_iter p1, Line_iter p2) :first(p1), last(p2) {}
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }

private:
    Line_iter first;
    Line_iter last;
};

using Mess_iter = std::vector<Message>::const_iterator;

// a Mail_file holds all the lines from a file and simplifies access to messages
struct Mail_file {
    std::string name;               // file name
    std::vector<std::string> lines; // the lines in order
    std::vector<Message> m;         // Messages in order

    explicit Mail_file(const std::string& filename);

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

bool find_from_addr(const Message& m, std::string& s);
std::string find_subject(const Message& m);

std::string get_sender(const Message& m);
std::string get_recipient(const Message& m);
std::string get_subject(const Message& m);

bool has_sender_addr(const Message& m, const std::string& addr);
bool has_sender_name(const Message& m, const std::string& name);
bool has_recipient_addr(const Message& m, const std::string& addr);
bool has_recipient_name(const Message& m, const std::string& name);
bool contains_subject(const Message& m, const std::string& subject);
