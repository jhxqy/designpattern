//
//  Adapter.hpp
//  Adapter
//
//  Created by 贾皓翔 on 2018/10/17.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Adapter_hpp
#define Adapter_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

//使用stack的函数;
template <typename T>
void needStack(std::stack<T> &stack,const T &e){
    std::cout<<e<<std::endl;
    stack.push(e);
    std::cout<<stack.empty()<<std::endl;
    stack.pop();
    std::cout<<stack.empty()<<std::endl;

}

//我们已经有了vector，要把vector适配成stack;
//通过多重继承;
template<typename T>
class StackAdapter:public std::stack<T>,std::vector<T>{
public:
    using std::vector<T>::push_back;
    using std::vector<T>::pop_back;
    void push(const T &e){
        push_back(e);
    }
    T pop(const T&e){
        return pop_back();
    }
};

template<typename T>
class StackAdapter2

#endif /* Adapter_hpp */
