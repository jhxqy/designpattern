//
//  Flyweight.hpp
//  DesignPattern
//
//  Created by 贾皓翔 on 2018/10/22.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Flyweight_hpp
#define Flyweight_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
class Piece{
public:
    enum Color{white,black};
    virtual void PrintPosition(int row,int column)=0;
    virtual ~Piece()=0;
};

class ConcretePiece:public Piece{
    Color color_;
public:
    ConcretePiece(Color color):color_(color){}
    virtual void PrintPosition(int r,int c)override;
};


class PieceFactory{
    std::map<std::string,Piece*> m;
public:
    Piece* getPiece(const std::string &s);
};


#endif /* Flyweight_hpp */
