//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/31.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Memento.hpp"
int main(){
    Caretaker *ct=new Caretaker;
    Originator o;
    o.setStatus("status 1");
    o.print();
    ct->add(o.createOriginator());
    o.setStatus("status 2");
    o.print();
    ct->add(o.createOriginator());
    o.setStatus("status 3");
    o.print();
    std::cout<<"当前恢复到第一次保存：";
    o.SetMemento(ct->get(0));
    o.print();
    std::cout<<"当前恢复到第二次保存：";
    o.SetMemento(ct->get(1));
    o.print();
    
}
