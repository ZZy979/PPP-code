#include "str_to_double.h"

#include <sstream>
#include <stdexcept>

// if possible, convert characters in s to floating-point value
double str_to_double(const std::string& s) {
    std::istringstream iss(s);  // make a stream so that we can read from s
    double d;
    iss >> d;
    if (!iss)
        throw std::runtime_error("double format error: " + s);
    return d;
}
