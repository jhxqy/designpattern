//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/21.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Decorator.hpp"
int main(){
    using namespace std;
    WashingMachine *nm=new NormalWashingMachine;
    nm->washing();
    cout<<"---------------"<<endl;
    WashingMachine *dm=new DehydrationDecorator(nm,60);
    dm->washing();
    cout<<"---------------"<<endl;
    WashingMachine *tm=new TimeDecorator(dm);
    tm->washing();

    
}
