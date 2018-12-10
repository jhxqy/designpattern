//
//  Machine.cpp
//  machine
//
//  Created by 贾皓翔 on 2018/12/10.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Machine.hpp"
#include "State.hpp"
Machine::Machine(){
    state_=Standby::Instance();
}
void Machine::CoinOperated(){
    state_->CoinOperated(this, &bs);
}
void Machine::choose(){
    state_->choose(this, &bs);
}
void Machine::end(){
    state_->end(this,&bs);
}
void Machine::enterBackStage(){
    state_->enterBackStage(this,&bs);
}
void Machine::changeState(State *s){
    state_=s;
}
