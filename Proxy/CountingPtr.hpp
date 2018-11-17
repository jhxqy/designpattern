//
//  CountingPtr.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/17.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef CountingPtr_hpp
#define CountingPtr_hpp

#include <stdio.h>
class CounterPolicy{
    size_t *count_;
public:
    CounterPolicy();
    ~CounterPolicy();
    void init();
    void disoise();
    void increment();
    void decrement();
    bool is_zero();
};
template<typename T>
class ObjectPolicy{
public:
    void dispose(T*);
};
template<typename T>
class ObjectPolicy<T[]>{
public:
    void dispose(T*);
};

template<typename T,typename CP=CounterPolicy,typename OP=ObjectPolicy<T>>
class CountingPtr:private CounterPolicy,private ObjectPolicy<T>{
    T* object_;
public:
    explicit CountingPtr(T*);
    CountingPtr(const CountingPtr&);
    ~CountingPtr();
    CountingPtr<T>& operator=(const CountingPtr&);
    inline T& operator*();
    inline T* operator->();
private:
    
};
#endif /* CountingPtr_hpp */
