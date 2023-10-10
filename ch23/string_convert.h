#pragma once

#include <sstream>
#include <string>

template<class T>
std::string to_string(const T& t) {
    std::ostringstream os;
    os << t;
    return os.str();
}

// class for reporting string cast errors
struct bad_from_string : std::bad_cast {
    const char* what() const noexcept override {
        return "bad cast from string";
    }
};

template<class T>
T from_string(const std::string& s) {
    std::istringstream is(s);
    T t;
    if (!(is >> t)) throw bad_from_string();
    return t;
}

template<class Target, class Source>
Target to(Source source) {
    std::stringstream interpreter;
    Target target;

    if (!(interpreter << source)                // write source into stream
            || !(interpreter >> target)         // read target from stream
            || !(interpreter >> std::ws).eof()) // stuff left in stream?
        throw std::bad_cast();
    return target;
}
