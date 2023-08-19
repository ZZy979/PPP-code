#pragma once

class Larger_than {
public:
    explicit Larger_than(int v) :v(v) {}            // store the argument
    bool operator()(int x) const { return x > v; }  // compare

private:
    int v;
};
