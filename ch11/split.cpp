#include "split.h"

#include "punct_stream.h"

const std::string DEFAULT_WHITESPACE = " \t\r\n\f\v";

// split s into whitespace-separated substrings
void split(const std::string& s, std::vector<std::string>& v) {
    split(s, "", v);
}

// split s into whitespace-separated substrings,
// where "whitespace" is defined as default whitespaces plus the characters in w
void split(const std::string& s, const std::string& w, std::vector<std::string>& v) {
    std::istringstream iss(s);
    Punct_stream ps(iss);
    ps.whitespace(w + DEFAULT_WHITESPACE);

    for (std::string word; ps >> word;)
        v.push_back(word);
}
