#include "variable.h"

// return the value of the variable named name
double Symbol_table::get_value(const std::string& name) const {
    if (var_table.find(name) == var_table.end())
        throw Variable_error("undefined variable " + name);
    return var_table.at(name);
}

// set the variable named name to value
void Symbol_table::set_value(const std::string& name, double value) {
    if (var_table.find(name) == var_table.end())
        throw Variable_error("undefined variable " + name);
    var_table[name] = value;
}

// is variable named name already declared?
bool Symbol_table::is_declared(const std::string& name) const {
    return var_table.find(name) != var_table.end();
}

// define variable named name with value
double Symbol_table::define_name(const std::string& name, double value) {
    if (var_table.find(name) != var_table.end())
        throw Variable_error(name + " declared twice");
    var_table[name] = value;
    return value;
}
