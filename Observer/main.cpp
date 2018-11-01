//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/1.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Observer.hpp"
int main(){
    ConcreteSubject * cs=new ConcreteSubject;
    ConcreteObserver *co1=new ConcreteObserver("co1");
    ConcreteObserver *co2=new ConcreteObserver("co2");
    ConcreteObserver *co3=new ConcreteObserver("co3");
    cs->attach(co1);
    cs->attach(co2);
    cs->attach(co3);
    cs->setStatus("helloworld");
    cs->setStatus("hi baby");
    cs->detach(co3);
    cs->setStatus("helloworld");


}
