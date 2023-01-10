#pragma once

#include <iostream>
#include <string>
#include <vector>

// holding n (name,age) pairs
class Name_pairs {
public:
    Name_pairs(int n) :n(n), name_age(n) {}

    void read_names(std::istream& is);
    void read_ages(std::istream& is);
    void print(std::ostream& os) const;
    void sort();

    bool operator==(const Name_pairs& other) const;
    bool operator!=(const Name_pairs& other) const;
private:
    int n;
    std::vector<std::pair<std::string, double>> name_age;
};

std::ostream& operator<<(std::ostream& os, const Name_pairs& p);
std::istream& operator>>(std::istream& is, Name_pairs& p);
