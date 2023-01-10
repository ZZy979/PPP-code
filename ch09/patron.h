#pragma once

#include <string>

class Patron {
public:
    Patron(const std::string& name, int card_number, double owed_fees);

    const std::string& name() const { return name_; }
    int card_number() const { return card_number_; }
    double owed_fees() const { return owed_fees_; }
    void set_owed_fees(double owed_fees) { owed_fees_ = owed_fees; }
    bool owes_fees() const { return owed_fees_ > 0; }
private:
    std::string name_;
    int card_number_;
    double owed_fees_;
};
