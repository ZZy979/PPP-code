#pragma once

#include <unordered_map>
#include <string>
#include <stdexcept>

class Symbol_table {
public:
    double get_value(const std::string& name) const;
    void set_value(const std::string& name, double value);
    bool is_declared(const std::string& name) const;
    double define_name(const std::string& name, double value);

private:
    std::unordered_map<std::string, double> var_table;
};

class Variable_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};
