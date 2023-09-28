#pragma once

#include <set>
#include <string>
#include <unordered_map>

// This class "cleans up" a text file for use in word query.
class Word_query {
public:
    Word_query() = default;
    explicit Word_query(const std::string& filename);

    bool open(const std::string& filename);
    void set_text(const std::string& text);

    int get_word_count(const std::string& word) const;
    std::pair<std::set<std::string>, int> get_most_frequent_words() const;
    std::set<std::string> get_longest_words() const;
    std::set<std::string> get_shortest_words() const;
    std::set<std::string> get_words_start_with(char c) const;
    std::set<std::string> get_words_by_length(size_t n) const;

private:
    using pair_type = std::pair<std::string, int>;
    void preprocess();
    void split_words();

    std::string text_;
    std::unordered_map<std::string, int> word_count_;
};

void normalize_quotes(std::string& text);
void remove_contractions(std::string& text);
void remove_punctuations(std::string& text);
void to_lower(std::string& text);
void stem_words(std::string& text);
void replace(std::string& s, const std::string& from, const std::string& to);
