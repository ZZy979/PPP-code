#include "function.h"

#include <cmath>
#include <stdexcept>

const std::unordered_set<std::string> one_argument_functions = {
    "sin", "cos", "tan", "exp", "log", "sqrt", "fabs"
};

const std::unordered_set<std::string> two_argument_functions = {
    "pow"
};

bool is_one_argument_function(const std::string& name) {
    return one_argument_functions.find(name) != one_argument_functions.end();
}

bool is_two_argument_function(const std::string& name) {
    return two_argument_functions.find(name) != two_argument_functions.end();
}

bool is_function_name(const std::string& name) {
    return is_one_argument_function(name) || is_two_argument_function(name);
}

double calculate_function(const std::string& name, double x, double y) {
    if (name == "sin")
        return sin(x);
    else if (name == "cos")
        return cos(x);
    else if (name == "tan")
        return tan(x);
    else if (name == "exp")
        return exp(x);
    else if (name == "log")
        return log(x);
    else if (name == "sqrt")
        return sqrt(x);
    else if (name == "fabs")
        return fabs(x);
    else if (name == "pow")
        return pow(x, y);
    else
        throw std::invalid_argument(name + " is not a function");
}
