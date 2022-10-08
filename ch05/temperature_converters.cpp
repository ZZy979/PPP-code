#include "temperature_converters.h"

#include <stdexcept>

// converts Celsius to Kelvin
double ctok(double c) {
    if (c < -273.15)
        throw std::invalid_argument("ctok: temperature can't be lower than -273.15 °C");
    return c + 273.15;
}

// converts Kelvin to Celsius
double ktoc(double k) {
    if (k < 0)
        throw std::invalid_argument("ktoc: temperature can't be lower than 0 K");
    return k - 273.15;
}

// converts Celsius to Fahrenheit
double ctof(double c) {
    if (c < -273.15)
        throw std::invalid_argument("ctof: temperature can't be lower than -273.15 °C");
    return 9.0 / 5 * c + 32;
}

// converts Fahrenheit to Celsius
double ftoc(double f) {
    if (f < -459.67)
        throw std::invalid_argument("ftoc: temperature can't be lower than -459.67 °F");
    return 5.0 / 9 * (f - 32);
}
