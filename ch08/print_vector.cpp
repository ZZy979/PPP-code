#include "print_vector.h"

// prints a vector of int to os, prefixing with label
void print(const std::string& label, const std::vector<int>& v, std::ostream& os) {
    os << label << " = {";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i < v.size() - 1)
            os << ", ";
    }
    os << '}';
}
