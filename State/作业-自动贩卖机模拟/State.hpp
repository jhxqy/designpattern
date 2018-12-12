//
//  State.hpp
//  machine
//
//  Created by 贾皓翔 on 2018/12/10.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include "Backstage.hpp"
#include <map>
#include <string>
class Machine;
class BackStage;
class State{
public:
    virtual void CoinOperated(Machine *v,BackStage *b)=0;
    virtual void choose(Machine *v,BackStage *b)=0;
    virtual void end(Machine *v,BackStage *b)=0;
    virtual void enterBackStage(Machine *v,BackStage *b)=0;
};

class Standby:public State{
    Standby(){}
    Standby(const Standby&){}
public:
    static Standby* Instance();
    void CoinOperated(Machine *v,BackStage *b);
    void choose(Machine *v,BackStage *b);
    void end(Machine *v,BackStage *b);
    void enterBackStage(Machine *v,BackStage *b);
};
class Buying:public State{
    Buying(){}
    Buying(const Buying&){}
    int money_;
    std::map<std::string,int> shoppingCart_;
public:
    static Buying* Instance(int);
    void CoinOperated(Machine *v,BackStage *b);
    void choose(Machine *v,BackStage *b);
    void end(Machine *v,BackStage *b);
    void enterBackStage(Machine *v,BackStage *b);
};
class Closing:public State{
    Closing(){}
    Closing(const Closing&){}
public:
    static Closing* Instance();
    void CoinOperated(Machine *v,BackStage *b);
    void choose(Machine *v,BackStage *b);
    void end(Machine *v,BackStage *b);
    void enterBackStage(Machine *v,BackStage *b);
};


#endif /* State_hpp */
