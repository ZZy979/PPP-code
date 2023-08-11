#pragma once

#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

// a line is a vector of characters
using Line = std::vector<char>;

/**
 * keep track of line and character position within a line
 *
 * invariant: ln->begin() <= pos < line->end(), except for the empty line at end of Document
 */
class Text_iterator : public std::iterator<std::forward_iterator_tag, char> {
public:
    // start the iterator at line ll's character position pp:
    Text_iterator(std::list<Line>::iterator ll, Line::iterator pp) :ln(ll), pos(pp) {}

    std::list<Line>::iterator line() const { return ln; }
    Line::iterator position() const { return pos; }

    reference operator*() const { return *pos; }
    Text_iterator& operator++();

    bool operator==(const Text_iterator& other) const { return ln == other.ln && pos == other.pos; }
    bool operator!=(const Text_iterator& other) const { return !(*this == other); }

private:
    std::list<Line>::iterator ln;
    Line::iterator pos;
};

/**
 * a document is a list of lines
 *
 * invariant:
 * - line is not empty, line.back() is empty line
 * - each line[i] ends with '\n' except line[n-2] and line[n-1] (last empty line)
 */
struct Document {
    std::list<Line> line;
    using iterator = Text_iterator;

    Document() { line.emplace_back(); }

    iterator begin();
    iterator end();

    iterator insert(iterator p, iterator first, iterator last);
    iterator insert(iterator p, const std::string& s);
    iterator erase(iterator first, iterator last);
    int replace_all(const std::string& target, const std::string& replacement);
};

std::istream& operator>>(std::istream& is, Document& d);
std::ostream& operator<<(std::ostream& os, Document& d);
Document create_document(const std::string& text);
void erase_line(Document& d, int n);
Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s);
int character_count(Text_iterator first, Text_iterator last);
int word_count(Text_iterator first, Text_iterator last, std::function<bool(char)> is_whitespace);
int word_count(Text_iterator first, Text_iterator last);
int word_count(Text_iterator first, Text_iterator last, const std::string& whitespaces);
