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
#include <string>
class Component{
public:
    virtual void Operation();
    virtual void Add(const Component *c);
    virtual void Remove();
    virtual Component* GetChild();
    virtual ~Component()=0;
};
Component::~Component(){}

class Leaf:public Component{
    std::string name_;
public:
    Leaf(std::string name):name_(name){}
    void Operation() override;
};

class Composite:public Component{
    std::string name_;
public:
    Composite(std::string name):name_(name){}
};
#endif /* Composite_hpp */
