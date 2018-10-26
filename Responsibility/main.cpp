//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/26.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Responsibility.hpp"
int main(){
    Leaf *jhx=new Leaf("jhx");
    Leaf *zmm=new Leaf("zmm");
    Leaf *xqw=new Leaf("xqw");
    Leaf *qjw=new Leaf("qjw");
    Leaf *zxl=new Leaf("zxl");
    Composite *c1=new Composite("网络171");
    Composite *c1D=new Class(c1);
    c1D->Add(qjw);
    c1D->Add(xqw);
    Composite *c2=new Composite("网络172");
    Composite *c2D=new Class(c2);

    c2D->Add(jhx);
    c2D->Add(zmm);
    Composite *wl=new Composite("网络工程系");
    Composite *wlD=new Department(wl);
    wlD->Add(zxl);
    wlD->Add(c1);
    wlD->Add(c2);
    xqw->leave(10);
    
}
