//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/28.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Iterator.hpp"
using namespace std;
int main(){
    List<int> l;
    l.Append(5);
    l.Append(10);
    l.Append(15);
    
    cout<<l.Count();
}
