#pragma once

#include <vector>

/**
 * ownership_vector is like pvector but provides a mechanism for the user to
 * decide which objects are owned by the vector (i.e., which objects are deleted by the destructor)
 * 
 * @see GUI/Graph.h Vector_ref
 */
template<class T>
class ownership_vector {
public:
    ownership_vector() = default;

    ownership_vector(const ownership_vector&) = delete;
    ownership_vector& operator=(const ownership_vector&) = delete;

    ~ownership_vector() { for (T* p : owned_) delete p; }

    void push_back(T& s) { v_.push_back(&s); }
    void push_back(T* p) { v_.push_back(p); owned_.push_back(p); }

    T& operator[](int i) const { return *v_[i]; }

    int size() const { return v_.size(); }

private:
    std::vector<T*> v_;
    std::vector<T*> owned_;
};
