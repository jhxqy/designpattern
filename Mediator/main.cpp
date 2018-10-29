//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/29.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Mediator.hpp"
int main(){
    Mediator *m=new Mediator;
    People jhx("jhx",m);
    People zbl("zbl",m);
    People zmm("zmm",m);
    jhx.Sell(1000);
    zbl.Buy(1);
}
