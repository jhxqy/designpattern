//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/14.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Singleton.hpp"
using namespace std;
int main(){
    Singleton *s=Singleton::Instance();
    s->print();
    Singleton *s1=Singleton::Instance();
    s1->print();
    cout<<boolalpha<<(s1==s)<<endl;
}
