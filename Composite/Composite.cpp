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
void Leaf::Operator(int n){
    for(int i=0;i<n;i++){
        cout<<"--";
    }
    cout<<name_<<endl;
}
void Composite::Add(Component *c){
    v.push_back(c);
    c->setFather(this);
}


void Composite::Remove(int n){
    v.erase(v.begin()+n);
}

Component* Composite::GetChild(int n){
    return v[n];
}

void Composite::Operator(int n){
    for(int i=0;i<n;i++){
        cout<<"--";
    }
    cout<<name_<<endl;
    for(auto i:v){
        (*i).Operator(n+1);
    }
}
