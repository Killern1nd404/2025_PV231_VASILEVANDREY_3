#ifndef SMARTPTR_H
#define SMARTPTR_H

#endif // SMARTPTR_H

template <typename T>
class SmartPtr {
    T *ptr_;

public:
    SmartPtr(T *ptr) : ptr_(ptr) {};
    ~SmartPtr() {delete ptr_;};
    T* operator->() const {return ptr_;};
    T& operator*() const {return *ptr_;};
};
