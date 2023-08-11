#pragma once

#include <vector>

/**
 * pvector is like vector of pointers except that it contains pointers to objects
 * and its destructor deletes each object
 */
template<class T>
class pvector {
public:
    pvector() = default;

    pvector(const pvector&) = delete;
    pvector& operator=(const pvector&) = delete;

    ~pvector() { for (T* p : v_) delete p; }

    void push_back(T* p) { v_.push_back(p); }
    T* operator[](int i) const { return v_[i]; }

    int size() const { return v_.size(); }

private:
    std::vector<T*> v_;
};
