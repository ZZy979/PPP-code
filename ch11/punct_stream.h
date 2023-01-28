#pragma once

#include <iostream>
#include <sstream>
#include <string>

// like an istream, but the user can add to the set of whitespace characters
class Punct_stream {
public:
    Punct_stream(std::istream& source) :source(source), sensitive(true) {}

    // make s the whitespace set
    void whitespace(const std::string& s) { white = s; }

    // add to the whitespace set
    void add_white(char c) { white += c; }

    // is c in the whitespace set?
    bool is_whitespace(char c) const;

    void case_sensitive(bool b) { sensitive = b; }

    bool is_case_sensitive() const { return sensitive; }

    virtual Punct_stream& operator>>(std::string& s);
    operator bool() const;

protected:
    std::istream& source;       // character source
    std::istringstream buffer;  // we let buffer do our formatting
    std::string white;          // characters considered "whitespace"
    bool sensitive;             // is the stream case-sensitive?
};
