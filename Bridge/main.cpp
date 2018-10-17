//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/17.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Bridge.hpp"
int main(){
    Square s;
    Color *white=new White,*black=new Black;
    s.setColor(white);
    s.draw();
    s.setColor(black);
    s.draw();
    Rectangle r;
    r.setColor(white);
    r.draw();
    r.setColor(black);
    r.draw();
}
