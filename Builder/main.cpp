//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/14.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Builder.hpp"
int main(){
    ComputerShop cs1=ComputerShop(Builder().setCpu("i7 7700").setGpu("GTX 1080").setRam("16G").setBrand("DELL"));
    Computer c1=cs1.Construct();
    c1.show();

    ComputerShop cs2=ComputerShop(Builder().setCpu("I5").setGpu("GTX 2080").setRam("8G").setBrand("IBM"));
    Computer c2=cs2.Construct();
    c2.show();

}
