#include "simple_text_editor.h"

#include <cctype>
#include <algorithm>
#include <sstream>

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

// insert characters in range [first, last) before p, return iterator to the first inserted character
Document::iterator Document::insert(Document::iterator p, Document::iterator first, Document::iterator last) {
    if (first == last) return p;

    int index = p.position() - p.line()->begin();
    Line remaining(p.position(), p.line()->end());
    p.line()->erase(p.position(), p.line()->end());

    auto it = p.line();
    for (; first != last; ++first) {
        it->push_back(*first);
        if (*first == '\n')
            it = line.emplace(std::next(it));
    }
    it->insert(it->end(), remaining.begin(), remaining.end());

    if (!line.back().empty())
        line.emplace_back();
    return {p.line(), p.line()->begin() + index};
}

// insert string s before p, return iterator to the first inserted character
Document::iterator Document::insert(Document::iterator p, const std::string& s) {
    Document d = create_document(s);
    return insert(p, d.begin(), d.end());
}

// remove characters in range [first, last), return iterator following the last removed character
Document::iterator Document::erase(Document::iterator first, Document::iterator last) {
    // last.position() != last.line()->end(), due to the invariant of Text_iterator,
    // so it's impossible to erase '\n' at end of line
    if (first.line() == last.line())
        return {first.line(), first.line()->erase(first.position(), last.position())};

    // special cases:
    // (1) if first.pos == first.ln->begin(), don't keep empty line after erasure
    // (2) if last == this->end(), don't remove the empty line after erasure
    if (last == end()) {
        first.line()->erase(first.position(), first.line()->end());
        line.erase(std::next(first.line()), last.line());
        if (first.line()->empty()) line.erase(first.line());
        return end();
    }

    first.line()->erase(first.position(), first.line()->end());
    auto pos = first.line()->insert(first.line()->end(), last.position(), last.line()->end());
    line.erase(std::next(first.line()), std::next(last.line()));
    return {first.line(), pos};
}

// replace all occurrences of target with replacement, return number of times replaced
int Document::replace_all(const std::string& target, const std::string& replacement) {
    int count = 0;
    for (auto it = begin(); it != end();) {
        if ((it = find_txt(it, end(), target)) == end())
            break;

        it = insert(erase(it, std::next(it, target.length())), replacement);
        std::advance(it, replacement.length());
        ++count;
    }
    return count;
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

Document create_document(const std::string& text) {
    Document d;
    std::istringstream iss(text);
    iss >> d;
    return d;
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

// counts the number of characters in [first, last)
int character_count(Text_iterator first, Text_iterator last) {
    return std::distance(first, last);
}

// counts the number of words in [first, last)
// "word" defined by is_whitespace
int word_count(Text_iterator first, Text_iterator last, std::function<bool(char)> is_whitespace) {
    int n = 0;
    for (bool in_word = false; first != last; ++first) {
        if (is_whitespace(*first))
            in_word = false;
        else if (!in_word) {
            in_word = true;
            ++n;
        }
    }
    return n;
}

// counts the number of words in [first, last)
// "word" defined as "default whitespace-separated sequence of characters"
int word_count(Text_iterator first, Text_iterator last) {
    return word_count(first, last, [](char c) -> bool { return isspace(c); });
}

// counts the number of words in [first, last)
// "word" defined as "custom whitespaces-separated sequence of characters"
int word_count(Text_iterator first, Text_iterator last, const std::string& whitespaces) {
    return word_count(first, last, [&whitespaces](char c) { return whitespaces.find(c) != std::string::npos; });
}
