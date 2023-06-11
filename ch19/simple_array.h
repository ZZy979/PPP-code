#pragma once

template<class T, int N>
struct array {
    T elem[N];  // hold elements in member array

    // rely on the default constructors, destructor, and assignment

    T& operator[](int i) { return elem[i]; }    // access: return reference
    const T& operator[](int i) const { return elem[i]; }

    T* data() { return elem; }      // conversion to T*
    const T* data() const { return elem; }

    int size() const { return N; }
};