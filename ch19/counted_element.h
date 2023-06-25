#pragma once

// for testing vector of class with resources
// use count() to assert constructor and destructor are called expected times
class Counted_element {
public:
    explicit Counted_element(int x = 0) :x_(x) { ++count_; }
    Counted_element(const Counted_element& e) :x_(e.x_) { ++count_; }
    ~Counted_element() { --count_; }

    static int count() { return count_; }
    int x() const { return x_; }

private:
    static int count_;
    int x_;
};
