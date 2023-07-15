#pragma once

#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

// a line is a vector of characters
using Line = std::vector<char>;

// keep track of line and character position within a line
class Text_iterator : public std::iterator<std::forward_iterator_tag, char> {
public:
    // start the iterator at line ll's character position pp:
    Text_iterator(std::list<Line>::iterator ll, Line::iterator pp) :ln(ll), pos(pp) {}

    reference operator*() const { return *pos; }
    Text_iterator& operator++();

    bool operator==(const Text_iterator& other) const { return ln == other.ln && pos == other.pos; }
    bool operator!=(const Text_iterator& other) const { return !(*this == other); }

private:
    std::list<Line>::iterator ln;
    Line::iterator pos;
};

// a document is a list of lines
struct Document {
    std::list<Line> line;
    using iterator = Text_iterator;

    Document() { line.emplace_back(); }

    iterator begin();
    iterator end();
};

std::istream& operator>>(std::istream& is, Document& d);
std::ostream& operator<<(std::ostream& os, Document& d);
void erase_line(Document& d, int n);
Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s);
