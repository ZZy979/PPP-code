#pragma once

#include <unordered_map>

#include "punct_stream.h"

// Punct_stream that
// (1) supports replace abbreviations (e.g. replace "don't" with "do not");
// (2) leaves hyphens within words intact (e.g. "as-if")
class Punct_stream_v2 : public Punct_stream {
public:
    Punct_stream_v2(std::istream& source,
            const std::unordered_map<std::string, std::string>& abbreviations)
            :Punct_stream(source), abbreviations(abbreviations) {}

    Punct_stream& operator>>(std::string& s) override;

protected:
    void replace_abbreviations(std::string& s) const;

    std::unordered_map<std::string, std::string> abbreviations;
};

void replace(std::string& s, const std::string& from, const std::string& to);
bool is_hyphen_within_words(const std::string& s, int i);
