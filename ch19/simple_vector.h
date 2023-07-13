#pragma once

#include <initializer_list>
#include <memory>
#include <stdexcept>

/**
 * An almost real vector of Ts
 *
 * invariant:
 * - if 0<=n<sz, elem[n] is element n
 * - sz<=space
 * - if sz<space there is space for (space–sz) Ts after elem[sz–1]
 */
template<class T, class A = std::allocator<T>>
class vector {
public:
    using size_type = unsigned long;
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;

    // default constructor
    vector() :sz(0), elem(nullptr), space(0) {}

    explicit vector(size_type n, const T& val = T());
    vector(std::initializer_list<T> lst);

    vector(const vector& v);                // copy constructor
    vector& operator=(const vector& v);     // copy assignment

    vector(vector&& v) noexcept;            // move constructor
    vector& operator=(vector&& v) noexcept; // move assignment

    ~vector() { destroy_and_deallocate(); } // destructor

    T& at(size_type i);                               // checked access
    const T& at(size_type i) const;

    T& operator[](size_type i) { return elem[i]; }    // access: return reference
    const T& operator[](size_type i) const { return elem[i]; }

    iterator begin() { return elem; }
    const_iterator begin() const { return elem; }
    iterator end() { return elem + sz; }
    const_iterator end() const { return elem + sz; }

    size_type size() const { return sz; }         // the current size
    size_type capacity() const { return space; }  // the current capacity

    void reserve(size_type new_space);
    void resize(size_type new_size, const T& val = T());
    void push_back(const T& val);

private:
    void construct(T* first, T* last, const T* from);
    void fill(T* first, T* last, const T& val);
    void destroy(T* first, T* last);
    void destroy_and_deallocate();

    size_type sz;       // the size
    T* elem;            // pointer to the elements
    size_type space;    // number of elements plus number of free slots
    A alloc;            // use allocate to handle memory for elements
};

// constructor: allocate n elements, let elem point to them, store n in sz
template<class T, class A>
vector<T, A>::vector(size_type n, const T& val)
        :sz(n), elem(alloc.allocate(n)), space(n) {
    fill(elem, elem + n, val);
}

// initializer-list constructor
template<class T, class A>
vector<T, A>::vector(std::initializer_list<T> lst)
        :sz(lst.size()), elem(alloc.allocate(lst.size())), space(lst.size()) {
    construct(elem, elem + lst.size(), lst.begin());
}

// copy constructor: define copy
template<class T, class A>
vector<T, A>::vector(const vector& v)
        :sz(v.sz), elem(alloc.allocate(v.space)), space(v.space) {
    construct(elem, elem + v.sz, v.elem);
}

// copy assignment: make this vector a copy of v
template<class T, class A>
vector<T, A>& vector<T, A>::operator=(const vector& v) {
    if (this == &v) return *this;   // self-assignment, no work needed

    if (v.sz <= space) {    // enough space, no need for new allocation
        destroy(elem, elem + sz);
        construct(elem, elem + v.sz, v.elem);     // copy elements
        sz = v.sz;
        return *this;
    }

    T* p = alloc.allocate(v.sz);        // allocate new space
    construct(p, p + v.sz, v.elem);     // copy elements
    destroy_and_deallocate();           // deallocate old space
    elem = p;           // set new elements
    space = sz = v.sz;  // set new size
    return *this;       // return a self-reference
}

// move constructor
template<class T, class A>
vector<T, A>::vector(vector&& v) noexcept :sz(v.sz), elem(v.elem), space(v.space) {
    v.space = v.sz = 0;     // make v the empty vector
    v.elem = nullptr;
}

// move assignment: move v to this vector
template<class T, class A>
vector<T, A>& vector<T, A>::operator=(vector&& v) noexcept {
    destroy_and_deallocate();   // deallocate old space
    elem = v.elem;      // copy v's elem and sz
    sz = v.sz;
    space = v.space;
    v.elem = nullptr;   // make v the empty vector
    v.space = v.sz = 0;
    return *this;       // return a self-reference
}

template<class T, class A>
T& vector<T, A>::at(size_type i) {
    if (i > sz) throw std::out_of_range("index out of range");
    return elem[i];
}

template<class T, class A>
const T& vector<T, A>::at(size_type i) const {
    if (i > sz) throw std::out_of_range("index out of range");
    return elem[i];
}

// increase the capacity
template<class T, class A>
void vector<T, A>::reserve(size_type new_space) {
    if (new_space <= space) return;     // never decrease allocation
    T* p = alloc.allocate(new_space);   // allocate new space
    construct(p, p + sz, elem);         // copy
    destroy_and_deallocate();           // deallocate old space
    elem = p;
    space = new_space;
}

// make the vector have new_size elements
// initialize each new element with val
template<class T, class A>
void vector<T, A>::resize(size_type new_size, const T& val) {
    reserve(new_size);
    fill(elem + sz, elem + new_size, val);  // construct
    destroy(elem + new_size, elem + sz);    // destroy
    sz = new_size;
}

// increase vector size by one; initialize the new element with val
template<class T, class A>
void vector<T, A>::push_back(const T& val) {
    if (space == 0)
        reserve(8);             // start with space for 8 elements
    else if (sz == space)
        reserve(2 * space);     // get more space
    alloc.construct(&elem[sz], val);    // add val at end
    ++sz;                       // increase the size (sz is the number of elements)
}

// copy construct elements in [first, last) from [from, from+(last-first))
template<class T, class A>
void vector<T, A>::construct(T* first, T* last, const T* from) {
    for (; first < last; ++first, ++from) alloc.construct(first, *from);
}

// copy construct elements in [first, last) from val
template<class T, class A>
void vector<T, A>::fill(T* first, T* last, const T& val) {
    for (; first < last; ++first) alloc.construct(first, val);
}

// destroy elements in [first, last)
template<class T, class A>
void vector<T, A>::destroy(T* first, T* last) {
    for (; first < last; ++first) alloc.destroy(first);
}

template<class T, class A>
void vector<T, A>::destroy_and_deallocate() {
    destroy(elem, elem + sz);
    alloc.deallocate(elem, space);
}
