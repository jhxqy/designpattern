//
//  main.cpp
//  Adapter
//
//  Created by 贾皓翔 on 2018/10/17.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Adapter.hpp"

int main(){
    StackAdapter<int> stack1;
    StackAdapter2<int> stack2;
    needStack(stack1,10);
    needStack(stack2, 20);
}
