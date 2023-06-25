#include "symbol_table.h"

// return the value of the variable named name
double Symbol_table::get_value(const std::string& name) const {
    int i = find(name);
    if (i == -1)
        throw Variable_error("undefined variable " + name);
    return var_table[i].second;
}

// set the variable named name to value
void Symbol_table::set_value(const std::string& name, double value) {
    int i = find(name);
    if (i == -1)
        throw Variable_error("undefined variable " + name);
    var_table[i].second = value;
}

// is variable named name already declared?
bool Symbol_table::is_declared(const std::string& name) const {
    return find(name) >= 0;
}

// define variable named name with value
double Symbol_table::define_name(const std::string& name, double value) {
    if (is_declared(name))
        throw Variable_error(name + " declared twice");
    var_table.push_back({name, value});
    return value;
}

int Symbol_table::find(const std::string& name) const {
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].first == name)
            return i;
    return -1;
}
