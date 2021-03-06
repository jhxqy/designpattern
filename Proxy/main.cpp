//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/26.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "VirtualProxy.hpp"
#include <ctime>
#include <iterator>
#include <cstdlib>
#include <iterator>
#include "CountingPtr.hpp"
using namespace std;
int main(){
    srand((unsigned)time(NULL));
    //需要大量的BigClass;
    CountingPtr<BigClassProxy> container[100];
    for(auto &i:container){
        i=new BigClassProxy(rand()%100);
        cout<<i->f()<<" ";
    }
    cout<<endl;
    //延迟了开销;
    container[45]->write();
    container[85]->write();
    CountingPtr<int> p(new int(5));
}
