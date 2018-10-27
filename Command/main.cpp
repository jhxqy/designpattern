//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/27.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Command.hpp"
int main(){
    Receiver1 *r1=new Receiver1;
    Command1 *c1=new Command1(r1);
    Invoker1 *i1=new Invoker1(c1);
    i1->Invoke();
    SimpleCommand<Receiver1> *r2=new SimpleCommand<Receiver1>(r1,&Receiver1::Action);
    Invoker1 *i2=new Invoker1(r2);
    i2->Invoke();
    
    
}
