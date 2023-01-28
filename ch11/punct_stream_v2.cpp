#include "punct_stream_v2.h"

Punct_stream& Punct_stream_v2::operator>>(std::string& s) {
    while (!(buffer >> s)) {    // try to read from buffer
        if (buffer.bad() || !source)
            return *this;
        buffer.clear();

        std::string line;
        std::getline(source, line);     // get a line from source

        if (!sensitive)
            for (char& ch : line)
                ch = tolower(ch);       // to lowercase

        replace_abbreviations(line);

        // do character replacement as needed:
        for (int i = 0; i < line.length(); ++i)
            if (is_whitespace(line[i]) && !is_hyphen_within_words(line, i))
                line[i] = ' ';                  // to space

        buffer.str(line);   // put string into stream
    }
    return *this;
}

void Punct_stream_v2::replace_abbreviations(std::string& s) const {
    for (const auto& p : abbreviations)
        replace(s, p.first, p.second);
}

// replace all occurrences of `from` in `s` with `to`
void replace(std::string& s, const std::string& from, const std::string& to) {
    if (from.empty() || from == to)
        return;
    for (size_t i = 0; (i = s.find(from, i)) != std::string::npos; i += to.length())
        s.replace(i, from.length(), to);
}

bool is_hyphen_within_words(const std::string& s, int i) {
    return s[i] == '-' && (i == 0 || isalpha(s[i - 1]))
            && (i == s.length() - 1 || isalpha(s[i + 1]));
}
