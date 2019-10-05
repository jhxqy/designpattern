//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2019/10/5.
//  Copyright © 2019 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Bridge.hpp"
using namespace std;
struct A{
public:
    void OperatorA(){
        cout<<"OperatorA"<<endl;
    }
    void OperatorB(){
        cout<<"OperatorB"<<endl;
    }

};

struct B{
public:
//    void OperatorA(){
//        cout<<"OperatorA"<<endl;
//    }
    void OperatorB(){
        cout<<"OperatorB"<<endl;
    }
    void OperatorC(){
        cout<<"OperatorC"<<endl;
    }
};



int main(){
    InterFace<A> a;
    InterFace<B> b;
    a.OperatorA();
    b.OperatorB();
 //   b.operatorA();
    //  b.OperatorB();
}
