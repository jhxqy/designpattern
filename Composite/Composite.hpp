//
//  Composite.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/20.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Composite_hpp
#define Composite_hpp
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
    void Operator(int) override;
   // ~Leaf(){}
};



class Composite:public Component{
    std::string name_;
    std::vector<Component*> v;
public:
    Composite(std::string name):name_(name){
    }
    void Operator(int)override;
    void Add(Component *c)override;
    void Remove(int n)override;
    Component* GetChild(int n)override;
    ~Composite();
};

#endif /* Composite_hpp */
