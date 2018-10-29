//
//  Mediator.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/29.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Mediator.hpp"
int Mediator::Order::count=1;

void Mediator::Sell(const People &p, int price){
    Order o=Order(p.getName(),price);
    for(auto &i:peoples){
        if(i->getName()!=p.getName()){
            std::stringstream ss;
            ss<<p.getName()<<"想要卖房 价格:"<<price<<" id:"<<o.id;
            i->Receive(ss.str());
        }
    }
}

