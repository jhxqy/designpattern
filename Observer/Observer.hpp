//
//  Observer.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/1.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
class Observer;
class Subject{
public:
    virtual void attach(Observer* o)=0;
    virtual void detach(Observer* o)=0;
    virtual void notify()=0;
    virtual std::string getStatus()=0;
    virtual void setStatus(const std::string &s)=0;
    virtual ~Subject()=0;
};

class Observer{
public:
    virtual void setSubject(Subject *s)=0;
    virtual void update()=0;
    virtual ~Observer()=0;
};

class ConcreteSubject: public Subject{
    std::vector<Observer*> v;
    std::string status;
public:
    void attach(Observer *o);
    void detach(Observer *o);
    void notify();
    void setStatus(const std::string &s);
    std::string getStatus();
};

class ConcreteObserver:public Observer{
    std::string name_;
    Subject *subject_;
public:
    ConcreteObserver(const std::string &s):name_(s){}
    void update();
    void setSubject(Subject *s);
};
#endif /* Observer_hpp */
