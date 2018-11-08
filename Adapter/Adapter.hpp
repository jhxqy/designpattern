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
    using std::stack<T>::push;
    using std::stack<T>::pop;

    void push(const T &e){
        std::vector<T>::push_back(e);
    }
    void pop(){
        std::vector<T>::pop_back();
    }
    bool empty(){
        return std::vector<T>::empty();
    }
};
//使用组合
template<typename T>
class StackAdapter2:public std::stack<T>{
    std::vector<T> v;
    using std::stack<T>::push;
    using std::stack<T>::pop;

    void push(const T &e){
        v.push_back(e);
    }
    void pop(){
        v.pop_back();
    }
    bool empty(){
        return v.empty();
    }
    
};


#endif /* Adapter_hpp */
