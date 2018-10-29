//
//  Mediator.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/29.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Mediator_hpp
#define Mediator_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
class People;
class Mediator{
  
    
public:
    struct Order{
        std::string name;
        int id;
        int price;
        Order(const std::string &n,int p):name(n),price(p),id(count++){}
    private:
        static int count;
    };
    
    void addPeople(People* p){
        peoples.push_back(p);
    }
    void Buy(const People &p,int id);
    void Sell(const People &p,int price);
private:

    std::vector<People*> peoples;
    std::vector<Order> orders;
};

class ThirdParty{
public:
    void Complaint(const People &a,const People &b);
};

class People{
    std::string name_;
    Mediator *m;
public:
    People(const std::string &s,Mediator *mm):name_(s),m(mm){}
    const std::string& getName()const{
        return name_;
    }
    void Buy(int id);
    void Sell(int price);
    void Complaint(int id);
    void Receive(const std::string &s);
};

#endif /* Mediator_hpp */
