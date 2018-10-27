//
//  Command.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/27.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp
#include <iostream>
#include <stdio.h>
//抽象命令类
class Command{
public:
    virtual ~Command(){}
    virtual void Execute()=0;
};
//抽象调用者
class Invoker{
public:
    virtual ~Invoker(){}
    virtual void Invoke()=0;
};
//接受者1
class Receiver1{
public:
    void Action();
};
#endif /* Command_hpp */
//命令一号，用于接受者1;
class Command1:public Command{
    Receiver1 *r1;
public:
    Command1(Receiver1 *r):r1(r){}
    void Execute()override;
};

class Invoker1:public Invoker{
    Command *c1;
public:
    Invoker1(Command *c):c1(c){}
    void Invoke()override;
};


template <typename R>
class SimpleCommand:public Command{
    typedef void (R::*Action)();
    Action action_;
    R *receiver_;
public:
    SimpleCommand(R *r,Action a):action_(a),receiver_(r){}
    void Execute()override;
};

template <typename R>
void SimpleCommand<R>::Execute(){
    (receiver_->*action_)();
}


