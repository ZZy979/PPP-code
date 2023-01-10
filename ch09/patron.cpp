#include "patron.h"

Patron::Patron(const std::string& name, int card_number, double owed_fees)
        :name_(name), card_number_(card_number), owed_fees_(owed_fees) {
}
