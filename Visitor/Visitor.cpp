//
//  Visitor.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/4.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Visitor.hpp"
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

void Leaf::Accept(Visitor *v){
    v->Visit(this);
}
void Composite::Accept(Visitor *vv){
    vv->Visit(this);
    for(auto i:v){
        i->Accept(vv);
    }
}

void NumVistor::Visit(Leaf *v){
    peopleNum++;
}
void NumVistor::Visit(Composite *c){
    CollectionNum++;
}

void NameVistor::Visit(Leaf *v){
    vect.push_back(v->getName());
}
void NameVistor::Visit(Composite *c){
    
}
