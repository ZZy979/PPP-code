#include "simple_text_editor.h"

#include <algorithm>

Text_iterator& Text_iterator::operator++() {
    ++pos;                  // proceed to next character
    if (pos == ln->end()) {
        ++ln;               // proceed to next line
        pos = ln->begin();  // bad if ln==line.end(); so make sure it isn't
    }
    return *this;
}

// first character of first line
Document::iterator Document::begin() {
    return {line.begin(), line.begin()->begin()};
}

// one beyond the last character of the last line
Document::iterator Document::end() {
    auto last = line.end();
    --last;     // we know that the document is not empty
    return {last, last->end()};
}

std::istream& operator>>(std::istream& is, Document& d) {
    for (char ch; is.get(ch);) {
        d.line.back().push_back(ch);    // add the character
        if (ch == '\n')
            d.line.emplace_back();      // add another line
    }
    if (!d.line.back().empty())
        d.line.emplace_back();          // add final empty line
    return is;
}

std::ostream& operator<<(std::ostream& os, Document& d) {
    for (auto c : d)
        os << c;
    return os;
}

// delete line n from document d
void erase_line(Document& d, int n) {
    if (n < 0 || n >= d.line.size() - 1) return;
    d.line.erase(std::next(d.line.begin(), n));
}

// find string s in text defined by [first, last)
// return iterator to first character, or last if not found
Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s) {
    if (s.empty()) return last;     // can't find an empty string
    return std::search(first, last, s.begin(), s.end());
}
