#include "person.h"

#include <stdexcept>

Person::Person(const std::string& name, int age) :name_(name), age_(age) {
    if (!is_valid_age(age))
        throw std::invalid_argument("Invalid age: " + std::to_string(age));
    if (!is_valid_name(name))
        throw std::invalid_argument("Invalid name: " + name);
}

bool is_valid_name(const std::string& name) {
    static const std::string invalid_chars = ";:\"'[]*&^%$#@!";
    return name.find_first_of(invalid_chars) == std::string::npos;
}

bool is_valid_age(int age) {
    return age >= 0 && age < 150;
}

std::istream& operator>>(std::istream& is, Person& p) {
    std::string name;
    int age;
    if (is >> name >> age)
        p = {name, age};
    return is;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    return os << p.name() << ' ' << p.age() << ' ' << (p.age() == 1 ? "year" : "years") << " old";
}
