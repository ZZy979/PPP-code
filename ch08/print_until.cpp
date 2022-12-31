#include "print_until.h"

// print until the first occurrence of quit
void print_until_s(const std::vector<std::string>& v, const std::string& quit, std::ostream& os) {
    for (const std::string& s : v) {
        if (s == quit)
            return;
        os << s << '\n';
    }
}

// print until the second occurrence of quit
void print_until_ss(const std::vector<std::string>& v, const std::string& quit, std::ostream& os) {
    bool seen = false;
    for (const std::string& s : v) {
        if (s == quit) {
            if (seen)
                return;
            else
                seen = true;
        }
        os << s << '\n';
    }
}
