#include "word_query.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <regex>
#include <sstream>
#include <unordered_set>

Word_query::Word_query(const std::string& filename) {
    open(filename);
}

bool Word_query::open(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs)
        return false;

    std::istreambuf_iterator<char> iit(ifs), eos;
    text_.assign(iit, eos);
    preprocess();
    return true;
}

void Word_query::set_text(const std::string& text) {
    text_ = text;
    preprocess();
}

int Word_query::get_word_count(const std::string& word) const {
    auto it = word_count_.find(word);
    return it == word_count_.end() ? 0 : it->second;
}

std::pair<std::set<std::string>, int> Word_query::get_most_frequent_words() const {
    int max_freq = std::max_element(
            word_count_.begin(), word_count_.end(),
            [](const pair_type& a, const pair_type& b) { return a.second < b.second; })->second;
    std::set<std::string> result;
    for (const auto& p : word_count_)
        if (p.second == max_freq)
            result.insert(p.first);
    return {result, max_freq};
}

std::set<std::string> Word_query::get_longest_words() const {
    size_t max_len = std::max_element(
            word_count_.begin(), word_count_.end(),
            [](const pair_type& a, const pair_type& b) { return a.first.length() < b.first.length(); })->first.length();
    std::set<std::string> result;
    for (const auto& p : word_count_)
        if (p.first.length() == max_len)
            result.insert(p.first);
    return result;
}

std::set<std::string> Word_query::get_shortest_words() const {
    size_t min_len = std::min_element(
            word_count_.begin(), word_count_.end(),
            [](const pair_type& a, const pair_type& b) { return a.first.length() < b.first.length(); })->first.length();
    std::set<std::string> result;
    for (const auto& p : word_count_)
        if (p.first.length() == min_len)
            result.insert(p.first);
    return result;
}

std::set<std::string> Word_query::get_words_start_with(char c) const {
    std::set<std::string> result;
    for (const auto& p : word_count_)
        if (p.first[0] == c)
            result.insert(p.first);
    return result;
}

std::set<std::string> Word_query::get_words_by_length(size_t n) const {
    std::set<std::string> result;
    for (const auto& p : word_count_)
        if (p.first.length() == n)
            result.insert(p.first);
    return result;
}

void Word_query::preprocess() {
    normalize_quotes(text_);
    remove_contractions(text_);
    remove_punctuations(text_);
    to_lower(text_);
    stem_words(text_);
    split_words();
}

void Word_query::split_words() {
    word_count_.clear();
    std::istringstream iss(text_);
    std::istream_iterator<std::string> iit(iss), eos;
    std::for_each(iit, eos, [this](const std::string& w) { ++word_count_[w]; });
}

// Normalize quotes in text: “ ” -> ", ‘ ’ -> '
void normalize_quotes(std::string& text) {
    static const std::regex RE_DOUBLE_QUOTES("“|”"), RE_SINGLE_QUOTES("‘|’");
    text = std::regex_replace(text, RE_DOUBLE_QUOTES, "\"");
    text = std::regex_replace(text, RE_SINGLE_QUOTES, "'");
}

// Remove contractions in text, e.g. don't -> do not
void remove_contractions(std::string& text) {
    static const std::unordered_map<std::string , std::string> CONTRACTIONS = {
        {"I'd", "I had"},
        {"I'll", "I will"},
        {"I'm", "I am"},
        {"I've", "I have"},
        {"you'd", "you had"},
        {"you'll", "you will"},
        {"you're", "you are"},
        {"you've", "you have"},
        {"he'd", "he had"},
        {"he'll", "he will"},
        {"he's", "he is"},
        {"she'd", "she had"},
        {"she'll", "she will"},
        {"she's", "she is"},
        {"it'd", "it had"},
        {"it'll", "it will"},
        {"it's", "it is"},
        {"we'd", "we had"},
        {"we'll", "we will"},
        {"we're", "we are"},
        {"we've", "we have"},
        {"they'd", "they had"},
        {"they'll", "they will"},
        {"they're", "they are"},
        {"they've", "they have"},
        {"who'd", "who had"},
        {"who'll", "who will"},
        {"who're", "who are"},
        {"who's", "who is"},
        {"who've", "who have"},
        {"what'll", "what will"},
        {"what're", "what are"},
        {"what's", "what is"},
        {"what've", "what have"},
        {"where's", "where is"},
        {"that's", "that is"},
        {"there's", "there is"},
        {"aren't", "are not"},
        {"can't", "can not"},
        {"couldn't", "could not"},
        {"didn't", "did not"},
        {"doesn't", "does not"},
        {"don't", "do not"},
        {"hadn't", "had not"},
        {"hasn't", "has not"},
        {"haven't", "have not"},
        {"isn't", "is not"},
        {"let's", "let us"},
        {"mightn't", "might not"},
        {"mustn't", "must not"},
        {"shan't", "shall not"},
        {"shouldn't", "should not"},
        {"weren't", "were not"},
        {"won't", "will not"},
        {"wouldn't", "would not"}
    };
    for (const auto& p : CONTRACTIONS)
        text = std::regex_replace(text, std::regex(p.first, std::regex::icase), p.second);
}

void remove_punctuations(std::string& text) {
    static const std::regex RE_PUNCT("[[:punct:]—]+");
    text = std::regex_replace(text, RE_PUNCT, " ");
}

void to_lower(std::string& text) {
    for (char& c : text)
        c = tolower(c);
}

// Stem words in text.
// Use very simple stemming algorithm: remove an "s" if you find both "ship" and "ships".
void stem_words(std::string& text) {
    std::istringstream iss(text);
    std::istream_iterator<std::string> iit(iss), eos;
    std::unordered_set<std::string> words(iit, eos);
    for (const std::string& w : words) {
        std::string plural = w + "s";
        if (words.find(plural) != words.end())
            replace(text, plural, w);
    }
}

// replace all occurrences of `from` in `s` with `to`
void replace(std::string& s, const std::string& from, const std::string& to) {
    if (from.empty() || from == to)
        return;
    for (size_t i = 0; (i = s.find(from, i)) != std::string::npos; i += to.length())
        s.replace(i, from.length(), to);
}
