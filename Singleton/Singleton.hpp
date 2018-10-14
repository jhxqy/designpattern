//
//  Singleton.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/14.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Singleton_hpp
#define Singleton_hpp

#include <stdio.h>
#include <iostream>
class Singleton{
private:
    int id;
    static Singleton* instance_;
protected:
    Singleton():id(0){}
public:
    static Singleton* Instance();
    void print();
};

#endif /* Singleton_hpp */
