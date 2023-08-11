#pragma once

#include <iterator>
#include <list>
#include <stdexcept>
#include <vector>

/**
 * Range-checked iterator for std::vector.
 * Its operator * and -> throws std::out_of_range if iterator is out-of-bound.
 */
template<class T>
class Range_checked_vector_iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    Range_checked_vector_iterator(std::vector<T>* vec, size_t index) :vec_(vec), index_(index) {}

    reference operator*() const { return vec_->at(index_); }
    pointer operator->() const { return &vec_->at(index_); }

    Range_checked_vector_iterator& operator++() { ++index_; return *this; }
    Range_checked_vector_iterator operator++(int) { return {vec_, index_++}; }
    Range_checked_vector_iterator& operator--() { --index_; return *this; }
    Range_checked_vector_iterator operator--(int) { return {vec_, index_--}; }

    Range_checked_vector_iterator& operator+=(difference_type n) { index_ += n; return *this; }
    Range_checked_vector_iterator operator+(difference_type n) const { return {vec_, index_ + n}; }
    Range_checked_vector_iterator& operator-=(difference_type n) { index_ -= n; return *this; }
    Range_checked_vector_iterator operator-(difference_type n) const { return {vec_, index_ - n}; }
    difference_type operator-(const Range_checked_vector_iterator& rhs) const { return index_ - rhs.index_; }

    bool operator==(const Range_checked_vector_iterator& rhs) const { return index_ == rhs.index_; }
    bool operator!=(const Range_checked_vector_iterator& rhs) const { return index_ != rhs.index_; }
    bool operator<(const Range_checked_vector_iterator& rhs) const { return index_ < rhs.index_; }
    bool operator<=(const Range_checked_vector_iterator& rhs) const { return index_ <= rhs.index_; }
    bool operator>(const Range_checked_vector_iterator& rhs) const { return index_ > rhs.index_; }
    bool operator>=(const Range_checked_vector_iterator& rhs) const { return index_ >= rhs.index_; }

private:
    std::vector<T>* vec_;
    size_t index_;
};

template<class T>
Range_checked_vector_iterator<T> range_checked_begin(std::vector<T>& vec) {
    return {&vec, 0};
}

template<class T>
Range_checked_vector_iterator<T> range_checked_end(std::vector<T>& vec) {
    return {&vec, vec.size()};
}

/**
 * Range-checked iterator for std::list.
 * Its operator ++ and -- throws std::out_of_range if iterator is out-of-bound.
 */
template<class T>
class Range_checked_list_iterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;
    using iterator_type = typename std::list<T>::iterator;

    Range_checked_list_iterator(std::list<T>* list, iterator_type iter) :list_(list), iter_(iter) {}

    reference operator*() const { return *iter_; }
    pointer operator->() const { return iter_.operator->(); }

    Range_checked_list_iterator& operator++() { check_right_bound(); ++iter_; return *this; }
    Range_checked_list_iterator operator++(int) { check_right_bound(); return {list_, iter_++}; }
    Range_checked_list_iterator& operator--() { check_left_bound(); --iter_; return *this; }
    Range_checked_list_iterator operator--(int) { check_left_bound(); return {list_, iter_--}; }

    bool operator==(const Range_checked_list_iterator& rhs) const { return iter_ == rhs.iter_; }
    bool operator!=(const Range_checked_list_iterator& rhs) const { return iter_ != rhs.iter_; }

private:
    void check_left_bound() { if (iter_ == list_->begin()) throw std::out_of_range("Iterator out of range"); }
    void check_right_bound() { if (iter_ == list_->end()) throw std::out_of_range("Iterator out of range"); }

    std::list<T>* list_;
    iterator_type iter_;
};

template<class T>
Range_checked_list_iterator<T> range_checked_begin(std::list<T>& list) {
    return {&list, list.begin()};
}

template<class T>
Range_checked_list_iterator<T> range_checked_end(std::list<T>& list) {
    return {&list, list.end()};
}
