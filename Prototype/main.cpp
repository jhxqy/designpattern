//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/14.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Prototype.hpp"
int main(){
    Message m1=Message(1,"1999","jhx");
    m1.print();
    Message m2=m1;
    m2.print();
}
