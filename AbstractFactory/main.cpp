//
//  main.cpp
//  AbstractFactory
//
//  Created by 贾皓翔 on 2018/10/13.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "AbstractFactory.hpp"
int main(){
    AbstractFactory *af=createFactory("male");
    Jacket *j=af->CreateJacket();
    j->show();
    Trousers *t=af->createTrousers();
    t->show();
    
    delete j;
    delete af;
    delete t;
    af=createFactory("female");
    j=af->CreateJacket();
    j->show();
    af->createTrousers();
    t->show();
}
