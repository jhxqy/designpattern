//
//  Bridge.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/17.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Bridge_hpp
#define Bridge_hpp

#include <stdio.h>
#include <iostream>
#include <string>
class Color{
public:
    virtual void bepaint(const std::string &shape)=0;
};
class Shape{
protected:
    Color *c;
public:
    void setColor(Color *cc){
        c=cc;
    }
    virtual void draw()=0;
};

class White:public Color{
public:
    void bepaint(const std::string &shape){
        std::cout<<"白色的："<<shape<<std::endl;
    }
};

class Black:public Color{
public:
    void bepaint(const std::string &shape){
        std::cout<<"黑色的："<<shape<<std::endl;
    }
};

class Rectangle:public Shape{
    
public:
    void draw(){
        c->bepaint("长方形");
    }
};

class Square:public Shape{
    
public:
    void draw(){
        c->bepaint("正方形");
    }
};

#endif /* Bridge_hpp */
