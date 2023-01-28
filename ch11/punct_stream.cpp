#include "punct_stream.h"

bool Punct_stream::is_whitespace(char c) const {
    return white.find(c) != std::string::npos;
}

Punct_stream& Punct_stream::operator>>(std::string& s) {
    while (!(buffer >> s)) {    // try to read from buffer
        if (buffer.bad() || !source)
            return *this;
        buffer.clear();

        std::string line;
        std::getline(source, line);     // get a line from source

        // do character replacement as needed:
        for (char& ch : line)
            if (is_whitespace(ch))
                ch = ' ';           // to space
            else if (!sensitive)
                ch = tolower(ch);   // to lowercase

        buffer.str(line);           // put string into stream
    }
    return *this;
}

Punct_stream::operator bool() const {
    return bool(source);
}
