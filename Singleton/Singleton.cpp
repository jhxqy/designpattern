//
//  Singleton.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/14.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Singleton.hpp"
using namespace std;

Singleton* Singleton::Instance(){
    static Singleton* instance_=nullptr;

    if(!instance_){
        instance_=new Singleton;
    }
    return instance_;
    
}

void Singleton::print(){
    cout<<"this is a singleton:address:"<<this<<endl;
}
