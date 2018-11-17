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
#include <iostream>
class CounterPolicy{
    size_t *count_;
public:
    CounterPolicy();
    ~CounterPolicy(){}
    void init();
    void dispose();
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
void ObjectPolicy<T>::dispose(T*t){
    delete t;
}
template<typename T>
class ArrrayPolicy{
public:
    void dispose(T* a){
        delete []a;
    }
};
template<typename T,typename CP=CounterPolicy,typename OP=ObjectPolicy<T>>
class CountingPtr:private CP,private OP{
    T* object_;
public:
    CountingPtr();
    explicit CountingPtr(T*);
    CountingPtr(const CountingPtr&);
    ~CountingPtr();
    CountingPtr<T>& operator=(T *p){
        if(this->object_==p){
            return *this;
        }
        this->detach();
        this->init(p);
        return *this;
    }
    CountingPtr<T>& operator=(const CountingPtr &cp){
        if(this->object_==cp.object_){
            return *this;
        }
        CP::operator=(cp);
        OP::operator=(cp);
        this->attach(cp);
        return *this;
    }
    inline T& operator*(){
        return *object_;
    }
    inline T* operator->(){
        return object_;
    }
private:
    void init(T *p){
        if(p!=nullptr){
            CP::init();
        }
        this->object_=p;
    }
    void attach(const CountingPtr &cp){
        this->object_=cp.object_;
        if (cp.object_!=nullptr) {
            CP::increment();
        }
    }
    void detach(){
        if(this->object_!=NULL){
            CP::decrement();
            if(CP::is_zero()){
                CP::dispose();
                OP::dispose(object_);
            }
            
        }
    }
};


template<typename T,typename CP,typename OP>
CountingPtr<T,CP,OP>::CountingPtr(){
    object_=nullptr;
}
template<typename T,typename CP,typename OP>
CountingPtr<T,CP,OP>::CountingPtr(T* p){
    this->init(p);
}
template<typename T,typename CP,typename OP>
CountingPtr<T,CP,OP>::CountingPtr(const CountingPtr<T,CP,OP>& cp):CP(cp),OP(cp){
    this->attach(cp);
}
template<typename T,typename CP,typename OP>
CountingPtr<T,CP,OP>::~CountingPtr(){
    this->detach();
}

#endif /* CountingPtr_hpp */
