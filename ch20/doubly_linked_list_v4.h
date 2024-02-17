#pragma once

#include <initializer_list>
#include <iterator>
#include <type_traits>

struct Node_base {
    Node_base* prev;    // previous link
    Node_base* succ;    // successor (next) link

    void insert(Node_base* n);
    void insert(Node_base* first, Node_base* last);
    void erase();
};

// insert n before this node
void Node_base::insert(Node_base* n) {
    n->succ = this;
    n->prev = prev;
    if (prev) prev->succ = n;
    prev = n;
}

// insert [first, last) before this node
void Node_base::insert(Node_base* first, Node_base* last) {
    if (this != last) {
        last->prev->succ = this;
        first->prev->succ = last;
        prev->succ = first;

        auto tmp = prev;
        prev = last->prev;
        last->prev = first->prev;
        first->prev = tmp;
    }
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

    reference operator*() const { return static_cast<Link<T>*>(node)->val; }  // get value (dereference)
    pointer operator->() const { return &static_cast<Link<T>*>(node)->val; }

    bool operator==(const List_iterator& b) const { return node == b.node; }
    bool operator!=(const List_iterator& b) const { return node != b.node; }

    Node_base* node;    // current link
};

// doubly-linked list const iterator
template<class T>
struct List_const_iterator {
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    explicit List_const_iterator(const Node_base* p) :node(p) {}

    List_const_iterator& operator++() { node = node->succ; return *this; }  // forward
    List_const_iterator& operator--() { node = node->prev; return *this; }  // backward

    reference operator*() const { return static_cast<const Link<T>*>(node)->val; }  // get value (dereference)
    pointer operator->() const { return &static_cast<const Link<T>*>(node)->val; }

    bool operator==(const List_const_iterator& b) const { return node == b.node; }
    bool operator!=(const List_const_iterator& b) const { return node != b.node; }

    const Node_base* node;  // current link
};

template<class Iter, class Tag>
using is_iterator = std::is_convertible<typename std::iterator_traits<Iter>::iterator_category, Tag>;

template<class Iter>
using is_input_iterator = is_iterator<Iter, std::input_iterator_tag>;

// doubly-linked list
template<class T>
class list {
public:
    using size_type = size_t;
    using value_type = T;
    using iterator = List_iterator<T>;
    using const_iterator = List_const_iterator<T>;

    list() { _init(); }

    explicit list(size_type n, const T& val = T()) {
        _init();
        for (size_type i = 0; i < n; ++i) push_back(val);
    }

    template<class InputIt, class = std::enable_if_t<is_input_iterator<InputIt>::value>>
    list(InputIt first, InputIt last) {
        _init();
        for (; first != last; ++first) push_back(*first);
    }

    list(std::initializer_list<T> lst) :list(lst.begin(), lst.end()) {}

    list(const list& l) :list(l.begin(), l.end()) {}

    list& operator=(const list& l) {
        if (this != &l) assign(l.begin(), l.end());
        return *this;
    }

    list(list&& l) noexcept { _move(std::move(l)); }

    list& operator=(list&& l) noexcept {
        _clear();
        _move(std::move(l));
        return *this;
    }

    ~list() { _clear(); }

    // iterator to first element
    iterator begin() { return iterator(head.succ); }
    const_iterator begin() const { return const_iterator(head.succ); }

    // iterator to one beyond last element
    iterator end() { return iterator(&head); }
    const_iterator end() const { return const_iterator(&head); }

    iterator insert(iterator p, const T& v);
    iterator insert(iterator p, size_type n, const T& val);

    template<class InputIt, class = std::enable_if_t<is_input_iterator<InputIt>::value>>
    iterator insert(iterator p, InputIt first, InputIt last);

    iterator erase(iterator p);
    iterator erase(iterator first, iterator last);

    void clear() { _clear(); _init(); }

    void assign(size_type n, const T& val);

    template<class InputIt, class = std::enable_if_t<is_input_iterator<InputIt>::value>>
    void assign(InputIt first, InputIt last);

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
    const T& front() const { return *begin(); }

    // the last element
    T& back() { return *std::prev(end()); }
    const T& back() const { return *std::prev(end()); }

    size_type size() const { return sz; }
    bool empty() const { return sz == 0; }

    void splice(iterator p, list& l) { splice(p, l, l.begin(), l.end()); }
    void splice(iterator p, list& l, iterator first, iterator last);

private:
    void _init();
    void _clear();
    void _move(list&& l);

    Node_base head; // virtual head node
    size_type sz;   // number of elements
};

// insert v into list before p
template<class T>
typename list<T>::iterator list<T>::insert(iterator p, const T& v) {
    auto tmp = new Link<T>(v);
    p.node->insert(tmp);
    ++sz;
    return iterator(tmp);
}

// insert n copies of val into list before p
template<class T>
typename list<T>::iterator list<T>::insert(iterator p, size_type n, const T& val) {
    if (n == 0) return p;
    list<T> tmp(n, val);
    iterator it = tmp.begin();
    splice(p, tmp);
    return it;
}

// insert [first, last) into list before p
template<class T>
template<class InputIt, class>
typename list<T>::iterator list<T>::insert(iterator p, InputIt first, InputIt last) {
    if (first == last) return p;
    list<T> tmp(first, last);
    iterator it = tmp.begin();
    splice(p, tmp);
    return it;
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

// remove [first, last) from the list
template<class T>
typename list<T>::iterator list<T>::erase(iterator first, iterator last) {
    while (first != last)
        first = erase(first);
    return last;
}

// replace the contents with n copies of val
template<class T>
void list<T>::assign(size_type n, const T& val) {
    iterator curr = begin(), end_ = end();
    for (; curr != end_ && n > 0; ++curr, --n)
        *curr = val;
    if (n > 0)
        insert(end_, n, val);
    else
        erase(curr, end_);
}

// replace the contents with [first, last)
template<class T>
template<class InputIt, class>
void list<T>::assign(InputIt first, InputIt last) {
    iterator curr = begin(), end_ = end();
    for (; curr != end_ && first != last; ++curr, ++first)
        *curr = *first;
    if (first == last)
        erase(curr, end_);
    else
        insert(end_, first, last);
}

// transfer elements in [first, last) from l to this list, insert before p
template<class T>
void list<T>::splice(iterator p, list& l, iterator first, iterator last) {
    if (first != last) {
        size_t n = std::distance(first, last);
        p.node->insert(first.node, last.node);
        sz += n;
        l.sz -= n;
    }
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

template<class T>
void list<T>::_move(list&& l) {
    if (l.empty()) {
        _init();
    }
    else {
        head = l.head;
        head.succ->prev = head.prev->succ = &head;
        sz = l.sz;
        l._init();
    }
}
