//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/20.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Composite.hpp"

int main(){
    Leaf *jhx=new Leaf("jhx");
    Leaf *zmm=new Leaf("zmm");
    Leaf *xqw=new Leaf("xqw");
    Leaf *qjw=new Leaf("qjw");
    Leaf *zxl=new Leaf("zxl");
    Composite *c1=new Composite("网络171");
    c1->Add(qjw);
    c1->Add(xqw);
    Composite *c2=new Composite("网络172");
    c2->Add(jhx);
    c2->Add(zmm);
    Composite *wl=new Composite("网络工程");
    wl->Add(zxl);
    wl->Add(c1);
    wl->Add(c2);
    xqw->getFather()->getFather()->Operator(0);
   
}
