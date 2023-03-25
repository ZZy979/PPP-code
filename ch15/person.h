#pragma once

#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name, int age);

    const std::string& name() const { return name_; }
    int age() const { return age_; }

private:
    std::string name_;
    int age_;
};

bool is_valid_name(const std::string& name);
bool is_valid_age(int age);

std::istream& operator>>(std::istream& is, Person& p);
std::ostream& operator<<(std::ostream& os, const Person& p);
