#pragma once

#include <vector>

/**
 * ovector is like pvector except that the [] operators return a reference to the object
 * pointed to by an element rather than the pointer
 */
template<class T>
class ovector {
public:
    ovector() = default;

    ovector(const ovector&) = delete;
    ovector& operator=(const ovector&) = delete;

    ~ovector() { for (T* p : v_) delete p; }

    void push_back(T* p) { v_.push_back(p); }
    T& operator[](int i) const { return *v_[i]; }

    int size() const { return v_.size(); }
    
private:
    std::vector<T*> v_;
};
