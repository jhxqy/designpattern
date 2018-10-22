//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/22.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "Flyweight.hpp"
int main(){
    PieceFactory *pf=PieceFactory::Instance();
    Piece* Checkerboard[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i>j){
                Checkerboard[i][j]=pf->getPiece("black");
            }else{
                Checkerboard[i][j]=pf->getPiece("white");
            }
        }
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            Checkerboard[i][j]->PrintPosition(i, j);
        }
    }
}
