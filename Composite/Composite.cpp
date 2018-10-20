//
//  Composite.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/20.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Composite.hpp"
using namespace std;

Component::~Component(){}
void Leaf::Operator(int){
    
    cout<<"这是一个叶子："<<name_<<endl;
}
void Composite::Add(Component *c){
    v.push_back(c);
}


void Composite::Remove(int n){
    v.erase(v.begin()+n);

}

Component* Composite::GetChild(int n){
    return v[n];
}

void Composite::Operator(int){
    cout<<name_<<endl;
    for(auto i:v){
        (*i).Operator(0);
    }
}
