//
//  main.cpp
//  AbstractFactory
//
//  Created by 贾皓翔 on 2018/10/13.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include <memory>
#include "AbstractFactory.hpp"
using namespace std;
int main(){
    
    shared_ptr<AbstractFactory> af(createFactory("male"));
    shared_ptr<Jacket>j(af->CreateJacket());
    shared_ptr<Trousers> t(af->createTrousers());

    j->show();
    t->show();
   
    af.reset(createFactory("female"));
    j.reset(af->CreateJacket());
    t.reset(af->createTrousers());

    j->show();
    t->show();
}
