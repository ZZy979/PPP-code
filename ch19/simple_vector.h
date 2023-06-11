#pragma once

#include <algorithm>
#include <initializer_list>

/**
 * An almost real vector of Ts
 *
 * invariant:
 * - if 0<=n<sz, elem[n] is element n
 * - sz<=space
 * - if sz<space there is space for (space–sz) Ts after elem[sz–1]
 */
template<class T>
class vector {
public:
    // default constructor
    vector() :sz(0), elem(nullptr), space(0) {}

    // constructor: allocate s elements, let elem point to them, store s in sz
    explicit vector(int s) :sz(s), elem(new T[s]{T()}), space(s) {}

    vector(std::initializer_list<T> lst);

    vector(const vector& v);                // copy constructor
    vector& operator=(const vector& v);     // copy assignment

    vector(vector&& v) noexcept;            // move constructor
    vector& operator=(vector&& v) noexcept; // move assignment

    ~vector() { delete[] elem; }            // destructor: free memory

    T& operator[](int i) { return elem[i]; }    // access: return reference
    const T& operator[](int i) const { return elem[i]; }

    int size() const { return sz; }         // the current size
    int capacity() const { return space; }  // the current capacity

    void reserve(int new_space);
    void resize(int new_size);
    void push_back(const T& v);

private:
    int sz;     // the size
    T* elem;    // pointer to the elements
    int space;  // number of elements plus number of free slots
};

// initializer-list constructor
template<class T>
vector<T>::vector(std::initializer_list<T> lst)
        :sz(lst.size()), elem(new T[sz]), space(lst.size()) {
    std::copy(lst.begin(), lst.end(), elem);    // initialize (using std::copy())
}

// copy constructor: define copy
template<class T>
vector<T>::vector(const vector& v) :sz(v.sz), elem(new T[v.space]), space(v.space) {
    std::copy(v.elem, v.elem + sz, elem);
}

// copy assignment: make this vector a copy of v
template<class T>
vector<T>& vector<T>::operator=(const vector& v) {
    if (this == &v) return *this;   // self-assignment, no work needed

    if (v.sz <= space) {    // enough space, no need for new allocation
        std::copy(v.elem, v.elem + v.sz, elem);     // copy elements
        sz = v.sz;
        return *this;
    }

    T* p = new T[v.sz];                     // allocate new space
    std::copy(v.elem, v.elem + v.sz, p);    // copy elements
    delete[] elem;      // deallocate old space
    elem = p;           // set new elements
    space = sz = v.sz;  // set new size
    return *this;       // return a self-reference
}

// move constructor
template<class T>
vector<T>::vector(vector&& v) noexcept :sz(v.sz), elem(v.elem), space(v.space) {
    v.space = v.sz = 0;     // make v the empty vector
    v.elem = nullptr;
}

// move assignment: move v to this vector
template<class T>
vector<T>& vector<T>::operator=(vector&& v) noexcept {
    delete[] elem;      // deallocate old space
    elem = v.elem;      // copy v's elem and sz
    sz = v.sz;
    space = v.space;
    v.elem = nullptr;   // make v the empty vector
    v.space = v.sz = 0;
    return *this;       // return a self-reference
}

// increase the capacity
template<class T>
void vector<T>::reserve(int new_space) {
    if (new_space <= space) return;     // never decrease allocation
    T* p = new T[new_space];            // allocate new space
    std::copy(elem, elem + sz, p);      // copy old elements
    delete[] elem;                      // deallocate old space
    elem = p;
    space = new_space;
}

// make the vector have new_size elements
// initialize each new element with default value
template<class T>
void vector<T>::resize(int new_size) {
    reserve(new_size);
    for (int i = sz; i < new_size; ++i) elem[i] = T();  // initialize new elements
    sz = new_size;
}

// increase vector size by one; initialize the new element with v
template<class T>
void vector<T>::push_back(const T& v) {
    if (space == 0)
        reserve(8);             // start with space for 8 elements
    else if (sz == space)
        reserve(2 * space);     // get more space
    elem[sz] = v;   // add v at end
    ++sz;           // increase the size (sz is the number of elements)
}
