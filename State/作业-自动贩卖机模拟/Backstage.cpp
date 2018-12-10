//
//  Backstage.cpp
//  machine
//
//  Created by 贾皓翔 on 2018/12/10.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Backstage.hpp"
#include <iostream>
#include "Machine.hpp"
#include "State.hpp"
using namespace std;
BackStage::BackStage():income_(0){
    //读取商品信息和收入
}
void BackStage::addCommodity(){
    cout<<"请输入您要添加的商品名称:";
    string name;
    cin>>name;
    cout<<"请输入价格:";
    int price,n;
    cin>>price;
    cout<<"请输入数量:";
    cin>>n;
    typedef map<std::string,Commodity>::iterator Iter;
    Iter i=commoditys_.find(name);
    if(i==commoditys_.end()){
        commoditys_.insert(pair<string,Commodity>(name,Commodity(n,price)));
    }else{
        (*i).second.number+=n;
        (*i).second.price=price;
    }
    cout<<"添加成功！!"<<endl;
}
void BackStage::removeCommodity(){
    cout<<"请输入您要删除的商品名称:";
    string name;
    cin>>name;
    int n;
    cout<<"请输入数量:";
    cin>>n;
    typedef map<std::string,Commodity>::iterator Iter;
    Iter i=commoditys_.find(name);
    if(i==commoditys_.end()){
        cout<<"您输入的商品不存在"<<endl;
        return;
    }else{
        (*i).second.number-=n;
        if((*i).second.number<=0){
            commoditys_.erase(i);
        }
    }
    cout<<"删除成功！"<<endl;
}
void BackStage::showList() const{
    int n=1;
    cout<<"   商品名\t价格\t剩余数量"<<endl;
    for(map<std::string,Commodity>::const_iterator i=commoditys_.begin();i!=commoditys_.end();i++){
        cout<<n<<". "<<(*i).first<<"\t"<<(*i).second.price<<"\t"<<(*i).second.number<<endl;
    }
}


int BackStage::buy(const std::string &name,int n,int money){
    typedef map<std::string,Commodity>::iterator Iter;
    int result=-1;
    Iter i=commoditys_.find(name);
    if(i==commoditys_.end()){
        return result;
    }
    if((*i).second.number<n){
        return result;
    }
    income_+=n*(*i).second.price;
    result=money-n*(*i).second.price;
    (*i).second.number-=n;
    if((*i).second.number==0){
        commoditys_.erase(i);
    }
    return result;
}

BackStage::~BackStage(){ 
    
}
void BackStage::openOrClose(bool b,Machine &m){
    if (b) {
        m.changeState(Standby::Instance());
    }else{
        m.changeState(Closing::Instance());
    }
}
void BackStage::enterBS(Machine *m){
    while (true) {
        cout<<"欢迎进入后台！"<<endl;
        cout<<"1.添加商品"<<endl;
        cout<<"2.删除商品"<<endl;
        cout<<"3.查看收入"<<endl;
        cout<<"4.关闭/打开售货机"<<endl;
        cout<<"5.查看商品列表"<<endl;
        cout<<"6.返回"<<endl;
        int n;
        cin>>n;
        switch (n) {
            case 1:
                addCommodity();
                break;
            case 2:
                removeCommodity();
                break;
            case 3:
                cout<<"共计收入:"<<income_<<endl;
                break;
            case 4:
                int nn;
                cout<<"1. 打开 2.关闭 请输入:";
                cin>>nn;
                if(nn==1){
                    openOrClose(true, *m);
                    cout<<"成功打开！"<<endl;
                }else{
                    openOrClose(false, *m);
                    cout<<"成功关闭！"<<endl;

                }
                break;
            case 5:
                showList();
            
            default:
                return;
        }
    }
}
