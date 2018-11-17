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
template<typename T>
class CounterPolicy{
public:
    CounterPolicy();
    CounterPolicy(const CounterPolicy&);
    ~CounterPolicy();
    CounterPolicy& operator=(const CounterPolicy&);
    void init(T*);
    void disoise(T*);
    void increment(T*);
    void decrement(T*);
    bool is_zero(T*);
};
template <typename T>
class ObjectPolicy{
public:
    ObjectPolicy();
    ObjectPolicy(CounterPolicy<T> const&);
    ~ObjectPolicy();
    ObjectPolicy& operator=(const ObjectPolicy&);
    
    void dispose(T*);
};
template<typename T>
class CountingPtr{
    explicit CountingPtr(T*);
    CountingPtr(const CountingPtr&);
    ~CountingPtr();
    CountingPtr<T>& operator=(const CountingPtr&);
    inline T& operator*();
    inline T* operator->();
};
#endif /* CountingPtr_hpp */
