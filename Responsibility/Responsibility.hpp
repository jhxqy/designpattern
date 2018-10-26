//
//  Responsibility.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/26.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Responsibility_hpp
#define Responsibility_hpp
#include <stdio.h>
#include <iostream>
#include <vector>
class Component{
protected:
    Component *father;
    
public:
    void setFather(Component *f){
        father=f;
    }
    Component* getFather(){
        return father;
    }
    virtual void Operator(int){}
    virtual void leave(int){}
    virtual void Add(Component *c){}
    virtual void Remove(int){}
    virtual Component* GetChild(int){return nullptr;}
    virtual ~Component()=0;
    
};

class Leaf:public Component{
    std::string name_;
public:
    Leaf(std::string name):name_(name){
    }
    void leave(int) override;
    void Operator(int) override;
    // ~Leaf(){}
};



class Composite:public Component{
    std::string name_;
    std::vector<Component*> v;
    int n_;
public:
    Composite(std::string name,int n):name_(name),n_(n){
    }
    void Operator(int)override;
    void leave(int) override;

    void Add(Component *c)override;
    void Remove(int n)override;
    Component* GetChild(int n)override;
    ~Composite();
};



#endif /* Responsibility_hpp */
