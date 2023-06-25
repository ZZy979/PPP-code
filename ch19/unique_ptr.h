#pragma once

#include <utility>

/**
 * unique_ptr is a smart pointer that owns a T object through a pointer
 * and delete that object when the it is destroyed
 */
template<class T>
class unique_ptr {
public:
    explicit unique_ptr(T* ptr = nullptr) :ptr_(ptr) {}
    ~unique_ptr() { delete ptr_; }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr&& p) noexcept :ptr_(p.release()) {}
    unique_ptr& operator=(unique_ptr&& p) noexcept {
        if (this != &p) reset(p.release());
        return *this;
    }

    T* get() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
    explicit operator bool() const { return ptr_ != nullptr; }

    T* release() { return std::exchange(ptr_, nullptr); }
    void reset(T* ptr = nullptr) { delete std::exchange(ptr_, ptr); }
    void swap(unique_ptr& p) { std::swap(ptr_, p.ptr_); }

private:
    T* ptr_;
};
