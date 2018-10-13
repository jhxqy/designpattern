//
//  AbstractFactory.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/13.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "AbstractFactory.hpp"
using namespace std;
void MaleJacket::show(){
    cout<<"this is maleJacket"<<endl;
}
void FemaleJacket::show(){
    cout<<"this is FemaleJacket"<<endl;
}

void MaleTrousers::show(){;
    cout<<"this is a maleTrousers"<<endl;
}
void FemaleTrousers::show(){;
    cout<<"this is a femaleTrousers"<<endl;
}

Jacket* MaleFactory::CreateJacket(){
    return new MaleJacket;
}

Jacket* FemaleFactory::CreateJacket(){
    return new FemaleJacket;
}
Trousers* MaleFactory::createTrousers(){
    return new MaleTrousers;
}
Trousers* FemaleFactory::createTrousers(){
    return new FemaleTrousers;
}
AbstractFactory* createFactory(const std::string &s){
    if(s=="male"){
        return new MaleFactory;
    }
    if(s=="female"){
        return new FemaleFactory;
    }
    return nullptr;
}

