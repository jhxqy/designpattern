//
//  State.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/3.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef State_hpp
#define State_hpp
#include <iostream>
#include <stdio.h>
class State;

class VendingMachine{
    State *state_;
public:
    VendingMachine();
    void CoinOperated();
    void choose();
    void end();
    void changeState(State *s);
};
class State{
public:
    virtual void CoinOperated(VendingMachine *v)=0;
    virtual void choose(VendingMachine *v)=0;
    virtual void end(VendingMachine *v)=0;
};
class Standby:public State{
    static Standby *s;
    Standby(){}
public:
    static Standby* Instance();
    virtual void CoinOperated(VendingMachine *v);
    virtual void choose(VendingMachine *v);
    virtual void end(VendingMachine *v);
};

class Running:public State{
public:
    static Running *r;
    int money;
    Running(){}
public:
    static Running* Instance(int n);
    virtual void CoinOperated(VendingMachine *v);
    virtual void choose(VendingMachine *v);
    virtual void end(VendingMachine *v);
};
#endif /* State_hpp */
