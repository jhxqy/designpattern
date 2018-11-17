//
//  CountingPtr.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/17.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "CountingPtr.hpp"
CounterPolicy::CounterPolicy(){
    count_=NULL;
}
void CounterPolicy::init(){
    count_=new size_t(1);
}
void CounterPolicy::disoise(){
    delete count_;
}
void CounterPolicy::increment(){
    (*count_)++;
}
void CounterPolicy::decrement(){
    (*count_)--;
}
bool CounterPolicy::is_zero(){
    return *count_==0;
}
template<typename T>
void ObjectPolicy<T>::dispose(T*t){
    delete t;
}

template<typename T>
void ObjectPolicy<T[]>::dispose(T *t){
    delete[] t;
}

