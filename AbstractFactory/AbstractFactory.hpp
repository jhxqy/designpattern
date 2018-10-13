//
//  AbstractFactory.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/13.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef AbstractFactory_hpp
#define AbstractFactory_hpp

#include <iostream>

//abstractProduct的定义；
class Jacket{
public:
    virtual void show()=0;
    virtual ~Jacket(){}
};
class Trousers{
public:
    virtual void show()=0;
    virtual ~Trousers(){}
};
//抽象工厂
class AbstractFactory{
public:
    virtual Jacket* CreateJacket()=0;
    virtual Trousers* createTrousers()=0;
    virtual ~AbstractFactory(){};;;
};
//具体产品实现；

class MaleJacket:public Jacket{
public:
    void show();
};
class FemaleJacket:public Jacket{
public:
    void show();
};
class MaleTrousers:public Trousers{
public:
    void show();
};
class FemaleTrousers:public Trousers{
public:
    void show();
};

//具体工厂的实现；

class MaleFactory:public AbstractFactory{
    Jacket* CreateJacket();
    Trousers* createTrousers();
};

class FemaleFactory:public AbstractFactory{
    Jacket* CreateJacket();
    Trousers* createTrousers();
};

AbstractFactory* createFactory(const std::string &s);


#endif /* AbstractFactory_hpp */
