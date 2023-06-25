#pragma once

#include <cstdlib>

template<class T>
class Simple_allocator {
public:
    // allocate uninitialized storage for n objects of type T
    T* allocate(int n) { return static_cast<T*>(malloc(n * sizeof(T))); }

    // deallocate n objects of type T starting at p
    void deallocate(T* p, int n) { free(p); }

    // construct a T with the value v in p
    void construct(T* p, const T& v) { new(p) T(v); }

    // destroy the T in p
    void destroy(T* p) { p->~T(); }
};
