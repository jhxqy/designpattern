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
#include <vector>
class People;
class Mediator{
    std::vector<People*> peoples;
public:
    void addPeople(People* p){
        peoples.push_back(p);
    }
    void Buy(const People &p,int id);
    void Sell(const People &p,int price);
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
};

#endif /* Mediator_hpp */
