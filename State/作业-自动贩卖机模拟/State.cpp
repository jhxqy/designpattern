//
//  State.cpp
//  machine
//
//  Created by 贾皓翔 on 2018/12/10.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "State.hpp"
#include <iostream>
#include "Machine.hpp"
#include <utility>
using namespace std;
Standby* Standby::Instance(){
    static Standby *p=NULL;
    if(p==NULL){
        p=new Standby;
    }
    return p;
}
void Standby::CoinOperated(Machine *v, BackStage *b){
    cout<<"请输入您要投入的钱数:";
    int money;
    cin>>money;
    v->changeState(Buying::Instance(money));
    cout<<"投币成功 共投入："<<money<<"元！"<<endl<<endl;
}
void Standby::choose(Machine *v, BackStage *b){
    cout<<"您尚未投币，请先投币."<<endl<<endl;
}
void Standby::end(Machine *v, BackStage *b){
    cout<<"您尚未投币，请先投币."<<endl<<endl;
}
void Standby::enterBackStage(Machine *v,BackStage *b){
    b->enterBS(v);
}








Buying* Buying::Instance(int n){
    static Buying *p=NULL;
    if(p==NULL){
        p=new Buying;
    }
    p->money_=n;
    return p;
}

void Buying::CoinOperated(Machine *v, BackStage *b){
    cout<<"当前您已有:"<<money_<<"元,请输入继续投入的金额:";
    int m;
    cin>>m;
    money_+=m;
    cout<<"投币成功 当前剩余："<<money_<<"元！"<<endl<<endl;
}
void Buying::choose(Machine *v, BackStage *b){
    cout<<"当前您有:"<<money_<<"元，商品清单如下："<<endl;
    b->showList();
    cout<<"请输入您要购买的商品名称：";
    string name;
    cin>>name;
    int n;
    cout<<"请输入您要购买的数量：";
    cin>>n;
    int t=b->buy(name, n, money_);
    if(t<0){
        cout<<"余额不足或是商品库存不足，购买失败"<<endl<<endl;
        return;
    }
    money_=t;
    shoppingCart_.insert(pair<string, int>(name,n));
    cout<<"购买成功，您当前还有:"<<money_<<"元"<<endl<<endl;
}
void Buying::end(Machine *v, BackStage *b){
    typedef map<string,int>::iterator IterType;
    cout<<"您购买的商品如下:"<<endl;
    for(IterType i=shoppingCart_.begin();i!=shoppingCart_.end();i++){
        cout<<"  "<<(*i).first<<"\t"<<(*i).second<<endl;
    }
    shoppingCart_.clear();
    cout<<"剩余"<<money_<<"元，已退币。"<<endl<<endl;
    v->changeState(Standby::Instance());
}

void Buying::enterBackStage(Machine *v, BackStage *b){
    cout<<"您正在购买状态，请退币后再试！"<<endl<<endl;
}







Closing* Closing::Instance(){
    static Closing *p=NULL;
    if(p==NULL)
        p=new Closing;
    return p;
}
void Closing::CoinOperated(Machine *v, BackStage *b){
    cout<<"当前机器已关闭，请联系管理员！"<<endl<<endl;
}
void Closing::choose(Machine *v, BackStage *b){
    cout<<"当前机器已关闭，请联系管理员！"<<endl<<endl;

}
void Closing::end(Machine *v, BackStage *b){
    cout<<"当前机器已关闭，请联系管理员！"<<endl<<endl;
}

void Closing::enterBackStage(Machine *v, BackStage *b){
    b->enterBS(v);
}
