//
//  State.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/3.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "State.hpp"
using namespace std;
Standby* Standby::s=nullptr;
Running* Running::r=nullptr;

void VendingMachine::CoinOperated(){
    state_->CoinOperated(this);
}
void VendingMachine::choose(){
    state_->choose(this);
}
void VendingMachine::end(){
    state_->end(this);
}
void VendingMachine::changeState(State *s){
    state_=s;
}


Running* Running::Instance(int n){
    if(r==nullptr){
        r=new Running;
    }
    r->money=n;
    return r;
}
Standby* Standby::Instance(){
    if(s==nullptr){
        s=new Standby;
    }
    return s;
}
void Standby::CoinOperated(VendingMachine *v){
    int n;
    std::cout<<"请输入你要投的钱数:"<<std::endl;
    std::cin>>n;
    v->changeState(Running::Instance(n));
    std::cout<<"现在您有"<<n<<"元可以消费"<<std::endl;
}

void Standby::choose(VendingMachine *v){
    std::cout<<"请先投币！"<<std::endl;

}

void Standby::end(VendingMachine *v){
    std::cout<<"请先投币！"<<std::endl;

}

void Running::CoinOperated(VendingMachine *v){
    std::cout<<"请输入你要继续投的钱数:"<<std::endl;
    int n;
    std::cin>>n;
    money+=n;
    std::cout<<"现在您有"<<money<<"元可以消费"<<std::endl;
}
void Running::choose(VendingMachine *v){
    cout<<"您已选择了可乐一瓶，价值10元"<<endl;
    money-=10;
}

void Running::end(VendingMachine *v){
    cout<<"还剩余"<<money<<"元，已退出"<<endl;
    v->changeState(Standby::Instance());
}
