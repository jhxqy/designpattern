//
//  Responsibility.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/26.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Responsibility.hpp"
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
Composite::~Composite(){
    for(auto i:v){
        delete i;
    }
}
void Leaf::leave(int n){
    getFather()->leave(n);
}
void Composite::leave(int n){
    if(n<=n_){
        cout<<name_<<"准假"<<n<<"天！"<<endl;
    }else{
        getFather()->leave(n);
    }
}
