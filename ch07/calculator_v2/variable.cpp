#include "variable.h"

#include "function.h"

// return the value of the variable/constant named name
double Symbol_table::get_value(const std::string& name) const {
    if (var_table.find(name) == var_table.end())
        throw Variable_error("undefined variable " + name);
    return var_table.at(name).value;
}

// set the variable named name to value
void Symbol_table::set_value(const std::string& name, double value) {
    auto it = var_table.find(name);
    if (it == var_table.end())
        throw Variable_error("undefined variable " + name);
    else if (it->second.is_const)
        throw Variable_error("can't assign to constant");
    it->second.value = value;
}

// is variable/constant named name already declared?
bool Symbol_table::is_declared(const std::string& name) const {
    return var_table.find(name) != var_table.end();
}

// define variable/constant named name with value
double Symbol_table::define_name(const std::string& name, double value, bool is_const) {
    if (var_table.find(name) != var_table.end())
        throw Variable_error(name + " declared twice");
    if (is_function_name(name))
        throw Variable_error(name + " is a function name");
    var_table[name] = {name, value, is_const};
    return value;
}
