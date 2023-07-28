#pragma once

#include <stdexcept>

template<class T, size_t N>
struct array {
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;
    using size_type = size_t;

    T elem[N];  // hold elements in member array

    // rely on the default constructors, destructor, and assignment

    iterator begin() { return elem; }
    const_iterator begin() const { return elem; }
    iterator end() { return elem + N; }
    const_iterator end() const { return elem + N; }

    T& operator[](size_type i) { return elem[i]; }  // access: return reference
    const T& operator[](size_type i) const { return elem[i]; }

    T& at(size_type i);     // range-checked access
    const T& at(size_type i) const;

    size_type size() const { return N; }

    T* data() { return elem; }      // conversion to T*
    const T* data() const { return elem; }
};

template<class T, size_t N>
T& array<T, N>::at(size_type i) {
    if (i > N) throw std::out_of_range("index out of range");
    return elem[i];
}

template<class T, size_t N>
const T& array<T, N>::at(size_type i) const {
    if (i > N) throw std::out_of_range("index out of range");
    return elem[i];
}
