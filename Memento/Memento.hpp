//
//  Memento.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/31.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Memento_hpp
#define Memento_hpp
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
class Memento;

class Originator{
    std::string status;
public:
    Memento* createOriginator();
    void SetMemento(const Memento *m);
    void print();
    void setStatus(const std::string &s);
};

class Memento{
public:
    ~Memento(){}
private:
    std::string status;
    friend class Originator;
    Memento( const std::string &s):status(s){}
    std::string getStatus()const{
        return status;
    }
};
class Caretaker{
    std::vector<Memento*> v;
public:
    ~Caretaker(){
        for(auto &i:v){
            delete(i);
        }
    }
    void add(Memento * m){
        v.push_back(m);
    }
    Memento * get(std::vector<Memento*>::size_type index){
        return v[index];
    }
};


#endif /* Memento_hpp */
