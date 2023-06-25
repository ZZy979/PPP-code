#pragma once

#include <utility>

/**
 * counted_ptr holds a pointer to an object of type T.
 * When the last counted_ptr for a T is destroyed, its destructor deletes the T.
 */
template<class T>
class counted_ptr {
public:
    explicit counted_ptr(T* ptr = nullptr) :ptr_(ptr), use_count_(ptr ? new long(1) : nullptr) {}
    ~counted_ptr() { decr_count(); }

    counted_ptr(const counted_ptr& p) :ptr_(p.ptr_), use_count_(p.use_count_) { incr_count(); }

    counted_ptr& operator=(const counted_ptr& p) {
        counted_ptr(p).swap(*this);
        return *this;
    }

    counted_ptr(counted_ptr&& p) noexcept :ptr_(p.ptr_), use_count_(p.use_count_) {
        p.ptr_ = nullptr;
        p.use_count_ = nullptr;
    }

    counted_ptr& operator=(counted_ptr&& p) noexcept {
        counted_ptr(std::move(p)).swap(*this);
        return *this;
    }

    T* get() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
    explicit operator bool() const { return ptr_ != nullptr; }
    long use_count() const { return use_count_ ? *use_count_ : 0; }

    void reset(T* ptr = nullptr) { counted_ptr(ptr).swap(*this); }

    void swap(counted_ptr& p) {
        std::swap(ptr_, p.ptr_);
        std::swap(use_count_, p.use_count_);
    }

private:
    void incr_count() {
        if (use_count_)
            ++*use_count_;
    }

    void decr_count() {
        if (use_count_ && --*use_count_ == 0) {
            delete ptr_;
            delete use_count_;
        }
    }

    T* ptr_;
    long* use_count_;
};
