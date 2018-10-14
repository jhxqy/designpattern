//
//  Prototype.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/14.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Prototype_hpp
#define Prototype_hpp

#include <stdio.h>
#include <iostream>
#include <string>
class Message{
    int n;
    std::string date;
    std::string from;
public:
    Message(int nn,const std::string &d,const std::string &f):date(d),from(f){}
    Message(const Message &s):n(s.n),date(s.date),from(s.from){}
    void print();
};
#endif /* Prototype_hpp */
