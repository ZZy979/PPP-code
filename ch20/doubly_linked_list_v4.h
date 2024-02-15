#pragma once

#include <initializer_list>
#include <iterator>
#include <type_traits>

struct Node_base {
    Node_base* prev;    // previous link
    Node_base* succ;    // successor (next) link

    void insert(Node_base* n);
    void erase();
};

// insert n before this node
void Node_base::insert(Node_base* n) {
    n->succ = this;
    n->prev = prev;
    if (prev) prev->succ = n;
    prev = n;
}

// remove this node from list
void Node_base::erase() {
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
}

// doubly-linked list node
template<class T>
struct Link : public Node_base {
    T val;          // the value

    explicit Link(const T& v = T()) :Node_base{}, val(v) {}
};

// doubly-linked list iterator
template<class T>
struct List_iterator {
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    explicit List_iterator(Node_base* p) :node(p) {}

    List_iterator& operator++() { node = node->succ; return *this; }  // forward
    List_iterator& operator--() { node = node->prev; return *this; }  // backward

    T& operator*() { return static_cast<Link<T>*>(node)->val; }  // get value (dereference)
    T* operator->() { return &static_cast<Link<T>*>(node)->val; }

    bool operator==(const List_iterator& b) const { return node == b.node; }
    bool operator!=(const List_iterator& b) const { return node != b.node; }

    Node_base* node;    // current link
};

// doubly-linked list
template<class T>
class list {
public:
    using size_type = size_t;
    using value_type = T;
    using iterator = List_iterator<T>;
    // TODO const_iterator

    list() { _init(); }

    explicit list(size_type n, const T& val = T()) {
        _init();
        for (int i = 0; i < n; ++i) push_back(val);
    }

    template<class InputIt, typename std::enable_if<std::is_convertible<
            typename std::iterator_traits<InputIt>::iterator_category, std::input_iterator_tag>::value, int>::type = 0>
    list(InputIt first, InputIt last) {
        _init();
        for (; first != last; ++first) push_back(*first);
    }

    list(std::initializer_list<T> lst) :list(lst.begin(), lst.end()) {}

    ~list() { _clear(); }

    // TODO 拷贝构造、拷贝赋值、移动构造、移动赋值

    // iterator to first element
    iterator begin() { return iterator(head.succ); }

    // iterator to one beyond last element
    iterator end() { return iterator(&head); }

    iterator insert(iterator p, const T& v);
    iterator erase(iterator p);
    void clear() { _clear(); _init(); }

    // insert v at end
    void push_back(const T& v) { insert(end(), v); }

    // insert v at front
    void push_front(const T& v) { insert(begin(), v); }

    // remove the first element
    void pop_front() { erase(begin()); }

    // remove the last element
    void pop_back() { erase(iterator(head.prev)); }

    // the first element
    T& front() { return *begin(); }

    // the last element
    T& back() { return *std::prev(end()); }

    int size() const { return sz; }

private:
    void _init();
    void _clear();

    Node_base head; // virtual head node
    int sz;         // number of elements
};

// insert v into list before p
template<class T>
typename list<T>::iterator list<T>::insert(iterator p, const T& v) {
    auto tmp = new Link<T>(v);
    p.node->insert(tmp);
    ++sz;
    return iterator(tmp);
}

// remove p from the list
template<class T>
typename list<T>::iterator list<T>::erase(iterator p) {
    if (p == end()) return p;
    auto next = p.node->succ;
    p.node->erase();
    delete static_cast<Link<T>*>(p.node);
    --sz;
    return iterator(next);
}

template<class T>
void list<T>::_init() {
    head.prev = head.succ = &head;
    sz = 0;
}

template<class T>
void list<T>::_clear() {
    auto p = head.succ;
    while (p != &head) {
        auto next = p->succ;
        delete static_cast<Link<T>*>(p);
        p = next;
    }
}
