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
public:
    static Standby* Instance();
    virtual void CoinOperated(Machine *v,BackStage *b);
    virtual void choose(Machine *v,BackStage *b);
    virtual void end(Machine *v,BackStage *b);
    virtual void enterBackStage(Machine *v,BackStage *b);
};
class Buying:public State{
    Buying(){}
    int money_;
    std::map<std::string,int> shoppingCart_;
public:
    static Buying* Instance();
    virtual void CoinOperated(Machine *v,BackStage *b);
    virtual void choose(Machine *v,BackStage *b);
    virtual void end(Machine *v,BackStage *b);
    virtual void enterBackStage(Machine *v,BackStage *b);
};
class Closing:public State{
    Closing(){}
public:
    static Closing* Instance();
    virtual void CoinOperated(Machine *v,BackStage *b);
    virtual void choose(Machine *v,BackStage *b);
    virtual void end(Machine *v,BackStage *b);
    virtual void enterBackStage(Machine *v,BackStage *b);
};


#endif /* State_hpp */
