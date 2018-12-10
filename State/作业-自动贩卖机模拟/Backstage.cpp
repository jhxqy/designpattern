//
//  Backstage.cpp
//  machine
//
//  Created by 贾皓翔 on 2018/12/10.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Backstage.hpp"
#include <iostream>
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

