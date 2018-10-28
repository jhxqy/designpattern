//
//  Iterator.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/28.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>
#include <iostream>
#include <exception>
template<typename T>
class Iterator{
public:
     T& First();
     T& Next();
     bool IsDone();
};

template <typename T>
class AbstractList{
public:
    class ListIterator;
    ListIterator createIterator();
    int Count();
    void Append(T item);
    void Remove();
};


template<typename T>
class List:public AbstractList<T>{
    T data[100];
    int index;
public:
    class ListIterator:public Iterator<T>{
        List *list;
        int i;
    public:
        ListIterator(List *l):list(l),i(0){}
        T& First();
        T& Next();
        bool IsDone();
    };
    
    List():index(0){}
    ListIterator createIterator();
    int Count();
    void Append(T item);
    void Remove();
};
template<typename T>
void List<T>::Append(T item){
    if(index>99){
        throw std::out_of_range("容器满了");
    }
    data[index++]=item;
}

template<typename T>
void List<T>::Remove(){
    if(index==0){
        throw std::out_of_range("容器为空");
    }
    index--;
}

template<typename T>
int List<T>::Count(){
    return index;
}
template <typename T>
typename List<T>::ListIterator List<T>::createIterator() {
    return ListIterator(this);
}

template<typename T>
T& List<T>::ListIterator::First(){
    if(list->index==0){
        throw std::out_of_range("容器为空");
        
    }
    return list->data[0];
}

template<typename T>
T& List<T>::ListIterator::Next(){
    return list->data[i++];
}
template <typename T>
bool List<T>::ListIterator::IsDone(){
    return i>=list->index;
}

#endif /* Iterator_hpp */
