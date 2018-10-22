//
//  Flyweight.cpp
//  DesignPattern
//
//  Created by 贾皓翔 on 2018/10/22.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "Flyweight.hpp"
using namespace std;

void ConcretePiece::PrintPosition(int r, int c){
    switch (color_) {
        case Piece::black:
            cout<<r<<"行 "<<c<<"列 黑子"<<endl;
            break;
        case Piece::white:
            cout<<r<<"行 "<<c<<"列 白子"<<endl;
            break;
        default:
            break;
    }
}


Piece::~Piece(){}
PieceFactory* PieceFactory::instance=0;
PieceFactory* PieceFactory::Instance(){
    if(instance==0){
        instance=new PieceFactory;
    }
    return instance;
}

Piece* PieceFactory::getPiece(const std::string &s){
    map<string,Piece*>::iterator iter=m.find(s);
    if(iter==m.end()){
        if(s=="white"){
            auto p=new ConcretePiece(Piece::white);
            m.insert({"white",p});
            return p;
        }else{
            auto p=new ConcretePiece(Piece::black);
            m.insert({"black",p});
            return p;
        }
    }
    return iter->second;
}
