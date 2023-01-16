#include "get_int.h"

#include <cctype>
#include <stdexcept>

void skip_to_int(std::istream& is) {
    if (is.fail()) {    // we found something that wasn't an integer
        is.clear();     // we'd like to look at the characters
        for (char ch; is >> ch;) {  // throw away non-digits
            if (isdigit(ch) || ch == '-') {
                is.unget();     // put the digit back, so that we can read the number
                return;
            }
        }
    }
    throw std::runtime_error("no input");   // eof or bad: give up
}

// read an int from istream
int get_int(std::istream& is) {
    int n = 0;
    while (true) {
        if (is >> n) return n;
        std::cout << "Sorry, that was not a number; please try again\n";
        skip_to_int(is);
    }
}

// read an int in [low:high] from istream
int get_int(std::istream& is, int low, int high,
        const std::string& greeting, const std::string& sorry) {
    std::cout << greeting << ": [" << low << ':' << high << "]\n";
    while (true) {
        int n = get_int(is);
        if (low <= n && n <= high) return n;
        std::cout << sorry << ": [" << low << ':' << high << "]\n";
    }
}
