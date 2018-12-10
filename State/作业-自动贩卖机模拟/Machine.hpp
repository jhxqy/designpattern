//
//  Machine.hpp
//  machine
//
//  Created by 贾皓翔 on 2018/12/10.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Machine_hpp
#define Machine_hpp

#include <stdio.h>
#include "Backstage.hpp"
class State;
class Machine{
    State *state_;
    BackStage bs;
public:
    Machine();
    void CoinOperated();
    void choose();
    void end();
    void enterBackStage();
    void changeState(State *s);
};






#endif /* Machine_hpp */
