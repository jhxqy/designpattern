//
//  Command.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/27.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Command.hpp"
using namespace std;
void Receiver1::Action(){
    cout<<"Receiver 1 Action！"<<endl;
}

void Command1::Execute(){
    r1->Action();
}

void Invoker1::Invoke(){
    c1->Execute();
}
