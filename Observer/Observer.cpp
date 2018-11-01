//
//  Observer.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/1.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Observer.hpp"

void ConcreteSubject::attach(Observer *o){
    o->setSubject(this);
    v.push_back(o);
}
void ConcreteSubject::detach(Observer *o){
    auto i=v.begin();
    for(;*i!=o&&i!=v.end();i++);
    if(i!=v.end()){
        v.erase(i);
    }
}

void ConcreteSubject::setStatus(const std::string &s){
    status=s;
    notify();
}
std::string ConcreteSubject::getStatus(){
    return status;
}
////

void ConcreteObserver::setSubject(Subject *s){
    subject_=s;
}


void ConcreteSubject::notify(){
    for(auto &i:v){
        i->update();
    }
}
void ConcreteObserver::update(){
    std::cout<<name_<<"收到消息："<<subject_->getStatus()<<std::endl;

}
