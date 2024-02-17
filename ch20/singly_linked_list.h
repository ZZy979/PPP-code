#pragma once

#include <initializer_list>
#include <iterator>
#include <type_traits>

struct Node_base {
    Node_base* succ = nullptr;

    void insert_after(Node_base* n);
    void insert_after(Node_base* first, Node_base* last);
    void erase_after();
};

// insert n after this node
void Node_base::insert_after(Node_base* n) {
    n->succ = succ;
    succ = n;
}

// insert (first, last] after this node
void Node_base::insert_after(Node_base* first, Node_base* last) {
    auto tmp = first->succ;
    if (last) {
        first->succ = last->succ;
        last->succ = succ;
    }
    else {
        first->succ = nullptr;
    }
    succ = tmp;
}

// remove next node from list
void Node_base::erase_after() {
    succ = succ->succ;
}

// singly-linked list node
template<class T>
struct Link : public Node_base {
    T val;

    explicit Link(const T& v = T()) :Node_base{}, val(v) {}
};

// singly-linked list iterator
template<class T>
struct Slist_iterator {
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    explicit Slist_iterator(Node_base* p = nullptr) :node(p) {}

    Slist_iterator& operator++() { node = node->succ; return *this; }

    reference operator*() const { return static_cast<Link<T>*>(node)->val; }
    pointer operator->() const { return &static_cast<Link<T>*>(node)->val; }

    bool operator==(const Slist_iterator& b) const { return node == b.node; }
    bool operator!=(const Slist_iterator& b) const { return node != b.node; }

    Node_base* node;    // current link
};

// singly-linked list const iterator
template<class T>
struct Slist_const_iterator {
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    explicit Slist_const_iterator(const Node_base* p = nullptr) :node(p) {}

    Slist_const_iterator& operator++() { node = node->succ; return *this; }

    reference operator*() const { return static_cast<const Link<T>*>(node)->val; }
    pointer operator->() const { return &static_cast<const Link<T>*>(node)->val; }

    bool operator==(const Slist_const_iterator& b) const { return node == b.node; }
    bool operator!=(const Slist_const_iterator& b) const { return node != b.node; }

    const Node_base* node;  // current link
};

template<class Iter, class Tag>
using is_iterator = std::is_convertible<typename std::iterator_traits<Iter>::iterator_category, Tag>;

template<class Iter>
using is_input_iterator = is_iterator<Iter, std::input_iterator_tag>;

// singly-linked list
template<class T>
class slist {
public:
    using size_type = size_t;
    using value_type = T;
    using iterator = Slist_iterator<T>;
    using const_iterator = Slist_const_iterator<T>;

    slist() = default;

    explicit slist(size_type n, const T& val = T()) {
        for (auto p = &head; n; --n, p = p->succ)
            p->succ = new Link<T>(val);
    }

    template<class InputIt, class = std::enable_if_t<is_input_iterator<InputIt>::value>>
    slist(InputIt first, InputIt last) {
        for (auto p = &head; first != last; ++first, p = p->succ)
            p->succ = new Link<T>(*first);
    }

    slist(std::initializer_list<T> lst) :slist(lst.begin(), lst.end()) {}

    slist(const slist& l) :slist(l.begin(), l.end()) {}

    slist& operator=(const slist& l) {
        if (this != &l) assign(l.begin(), l.end());
        return *this;
    }

    slist(slist&& l) noexcept :head(l.head) { l.head.succ = nullptr; }

    slist& operator=(slist&& l) noexcept {
        clear();
        head.succ = l.head.succ;
        l.head.succ = nullptr;
        return *this;
    }

    ~slist() { clear(); }

    // iterator to one before forst element
    iterator before_begin() { return iterator(&head); }
    const_iterator before_begin() const { return const_iterator(&head); }

    // iterator to first element
    iterator begin() { return iterator(head.succ); }
    const_iterator begin() const { return const_iterator(head.succ); }

    // iterator to one beyond last element
    iterator end() { return iterator(nullptr); }
    const_iterator end() const { return const_iterator(nullptr); }

    iterator insert_after(iterator p, const T& v);
    iterator insert_after(iterator p, size_type n, const T& val);

    template<class InputIt, class = std::enable_if_t<is_input_iterator<InputIt>::value>>
    iterator insert_after(iterator p, InputIt first, InputIt last);

    iterator erase_after(iterator p);
    iterator erase_after(iterator first, iterator last);

    void clear();

    void assign(size_type n, const T& val);

    template<class InputIt, class = std::enable_if_t<is_input_iterator<InputIt>::value>>
    void assign(InputIt first, InputIt last);

    // insert v at front
    void push_front(const T& v) { insert_after(before_begin(), v); }

    // remove the first element
    void pop_front() { erase_after(before_begin()); }

    // the first element
    T& front() { return *begin(); }
    const T& front() const { return *begin(); }

    bool empty() const { return head.succ == nullptr; }

    void splice_after(iterator p, slist& l) { splice_after(p, l, l.before_begin(), l.end()); }

    // transfer elements in (first, last) from l to this list, insert after p
    void splice_after(iterator p, slist& l, iterator first, iterator last) { _splice_after(p, first, last); }

private:
    iterator _splice_after(iterator p, iterator first, iterator last);

    Node_base head; // virtual head node
};

// insert v into list after p
template<class T>
typename slist<T>::iterator slist<T>::insert_after(iterator p, const T& v) {
    auto tmp = new Link<T>(v);
    p.node->insert_after(tmp);
    return iterator(tmp);
}

// insert n copies of val into list after p
template<class T>
typename slist<T>::iterator slist<T>::insert_after(iterator p, slist::size_type n, const T& val) {
    if (n == 0) return p;
    slist<T> tmp(n, val);
    return _splice_after(p, tmp.before_begin(), tmp.end());
}

// insert [first, last) into list after p
template<class T>
template<class InputIt, class>
typename slist<T>::iterator slist<T>::insert_after(iterator p, InputIt first, InputIt last) {
    if (first == last) return p;
    slist<T> tmp(first, last);
    return _splice_after(p, tmp.before_begin(), tmp.end());
}

// remove element following p from the list
template<class T>
typename slist<T>::iterator slist<T>::erase_after(iterator p) {
    auto next = p.node->succ;
    p.node->erase_after();
    delete static_cast<Link<T>*>(next);
    return iterator(p.node->succ);
}

// remove (first, last) from the list
template<class T>
typename slist<T>::iterator slist<T>::erase_after(iterator first, iterator last) {
    while (first.node->succ != last.node)
        erase_after(first);
    return last;
}

template<class T>
void slist<T>::clear() {
    while (head.succ) {
        auto p = head.succ->succ;
        delete static_cast<Link<T>*>(head.succ);
        head.succ = p;
    }
}

// replace the contents with n copies of val
template<class T>
void slist<T>::assign(slist::size_type n, const T& val) {
    iterator prev = before_begin(), curr = begin(), end_ = end();
    for (; curr != end_ && n > 0; ++prev, ++curr, --n)
        *curr = val;
    if (n > 0)
        insert_after(prev, n, val);
    else if (curr != end_)
        erase_after(prev, end_);
}

// replace the contents with [first, last)
template<class T>
template<class InputIt, class>
void slist<T>::assign(InputIt first, InputIt last) {
    iterator prev = before_begin(), curr = begin(), end_ = end();
    for (; curr != end_ && first != last; ++prev, ++curr, ++first)
        *curr = *first;
    if (first != last)
        insert_after(prev, first, last);
    else if (curr != end_)
        erase_after(prev, end_);
}

template<class T>
typename slist<T>::iterator slist<T>::_splice_after(iterator p, iterator first, iterator last) {
    Node_base* e = first.node;
    while (e->succ != last.node) e = e->succ;
    if (first.node == e) return iterator(p);
    p.node->insert_after(first.node, e);
    return iterator(e);
}
