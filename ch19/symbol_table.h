#pragma once

#include <stdexcept>
#include <string>
#include <vector>

#include "pair.h"

/**
 * symbol table of variable (name, value)
 *
 * @see ch07/calculator_v2/variable.h
 */
class Symbol_table {
public:
    double get_value(const std::string& name) const;
    void set_value(const std::string& name, double value);
    bool is_declared(const std::string& name) const;
    double define_name(const std::string& name, double value);

private:
    int find(const std::string& name) const;

    std::vector<Pair<std::string, double>> var_table;
};

class Variable_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};
