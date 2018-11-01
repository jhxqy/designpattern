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
    virtual void attach(Observer* o);
    virtual void detach(Observer* o);
    virtual void setStatus(const std::string &s);
    virtual void notify();
    virtual std::string getStatus();
};

class Observer{
public:
    virtual void setSubject(Subject *s);
    virtual void update();
    virtual ~Observer(){}


};

class ConcreteSubject: public Subject{
    std::vector<Observer*> v;
    std::string status;
public:
    void attach(Observer *o)override;
    void detach(Observer *o)override;
    void notify()override;
    void setStatus(const std::string &s)override;
    std::string getStatus()override;
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
