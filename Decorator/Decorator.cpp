//
//  Decorator.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/21.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Decorator.hpp"
using namespace std;
void NormalWashingMachine::washing(){
    cout<<"洗衣服"<<endl;
}

void DehydrationDecorator::washing(){
    w_->washing();
    cout<<"把衣服甩干……"<< time_<<"s"<<endl;
}
void TimeDecorator::washing(){
    w_->washing();
    cout<<"共计用时……s"<<endl;
}
WashingMachine::~WashingMachine(){}
