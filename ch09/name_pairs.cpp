#include "name_pairs.h"

#include <algorithm>

// read a series of names from istream
void Name_pairs::read_names(std::istream& is) {
    for (auto& p : name_age)
        is >> p.first;
}

// read an age for each name from istream
void Name_pairs::read_ages(std::istream& is) {
    for (auto& p : name_age)
        is >> p.second;
}

// print out (name,age) pairs, one per line
void Name_pairs::print(std::ostream& os) const {
    for (const auto& p : name_age)
        os << '(' << p.first << ',' << p.second << ')' << std::endl;
}

// sort the name vector in alphabetical order and reorganize the age vector to match
void Name_pairs::sort() {
    std::sort(name_age.begin(), name_age.end());
}

bool Name_pairs::operator==(const Name_pairs& other) const {
    return name_age == other.name_age;
}

bool Name_pairs::operator!=(const Name_pairs& other) const {
    return name_age != other.name_age;
}

std::ostream& operator<<(std::ostream& os, const Name_pairs& p) {
    p.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Name_pairs& p) {
    p.read_names(is);
    p.read_ages(is);
    return is;
}
