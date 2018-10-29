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
    orders.push_back(o);
    for(auto &i:peoples){
        if(i->getName()!=p.getName()){
            std::stringstream ss;
            ss<<p.getName()<<"想要卖房 价格:"<<price<<" id:"<<o.id;
            i->Receive(ss.str());
        }
    }
}

void Mediator::Buy(const People &p, int id){
    for(auto &i:orders){
        if(i.id==id){
            std::stringstream ss;
            ss<<p.getName()<<"想要买你""的房子 价格:"<<i.price;
            for(auto &j:peoples){
                if(i.name==j->getName()){
                    std::cout<<p.getName()<<"想要买"<<j->getName()<<"的房子"<<std::endl;
                    j->Receive(ss.str());
                    break;
                }
            }
            break;
        }
    }
}

void People::Buy(int id){
    m->Buy(*this, id);
}
void People::Sell(int price){
    m->Sell(*this, price);
}
void People::Receive(const std::string &s){
    std::cout<<name_<<"收到:"<<s<<std::endl;
}
