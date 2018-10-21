//
//  Decorator.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/21.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Decorator_hpp
#define Decorator_hpp

#include <stdio.h>
#include <iostream>
class WashingMachine{
public:
    virtual void washing()=0;
    virtual ~WashingMachine()=0;
};

class NormalWashingMachine:public WashingMachine{
public:
    void washing();
};

class DehydrationDecorator:public WashingMachine{
private:
    int time_;
    WashingMachine *w_;
public:
    DehydrationDecorator(WashingMachine *w,int t):w_(w),time_(t){}
    void washing();
};


class TimeDecorator:public WashingMachine{
private:
    WashingMachine *w_;
public:
    TimeDecorator(WashingMachine *w):w_(w){}
    void washing();
};


#endif /* Decorator_hpp */
