//
//  Visitor.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/4.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Visitor_hpp
#define Visitor_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
class Leaf;
class Composite;
class Visitor{
public:
    virtual ~Visitor(){}
    virtual void Visit(Leaf *v)=0;
    virtual void Visit(Composite *c)=0;
};


class NumVistor:public Visitor{
    int peopleNum;
    int CollectionNum;
public:
    NumVistor():peopleNum(0),CollectionNum(0){}
    
    virtual void Visit(Leaf *v);
    virtual void Visit(Composite *c);
    std::pair<int,int> getNum(){
        return std::pair<int, int>(peopleNum,CollectionNum);
    }
};

class NameVistor:public Visitor{
    std::vector<std::string> vect;
public:
    void Visit(Leaf *v);
    void Visit(Composite *c);
    std::vector<std::string> getName(){
        return vect;
    }
};




class Component{
protected:
    Component *father;
    std::string name_;
    Component(const std::string &s):name_(s){}
public:
    void setFather(Component *f){
        father=f;
    }
    Component* getFather(){
        return father;
    }
    std::string getName(){
        return name_;
    }
    virtual void Accept(Visitor *v){}
    virtual void Operator(int){}
    virtual void Add(Component *c){}
    virtual void Remove(int){}
    virtual Component* GetChild(int){return nullptr;}
    virtual ~Component()=0;
};

class Leaf:public Component{
public:
    Leaf(const std::string &n):Component(n){
    }
    void Operator(int) override;
    void Accept(Visitor *v)override;
    // ~Leaf(){}
};

class Composite:public Component{
    std::vector<Component*> v;
public:
    Composite(const std::string &n):Component(n){
    }
    void Accept(Visitor *v)override;
    void Operator(int)override;
    void Add(Component *c)override;
    void Remove(int n)override;
    Component* GetChild(int n)override;
    ~Composite();
};


#endif /* Visitor_hpp */
