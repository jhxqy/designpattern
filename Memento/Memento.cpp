//
//  Memento.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/31.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Memento.hpp"

Memento* Originator::createOriginator(){
    return new Memento(status);
}
void Originator::SetMemento(const Memento *m){
    status=m->getStatus();
}

void Originator::print(){
    std::cout<<status<<std::endl;
}

void Originator::setStatus(const std::string &s){
    status=s;
}
