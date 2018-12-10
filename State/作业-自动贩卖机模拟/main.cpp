//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/12/10.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Backstage.hpp"
using namespace std;
int main(){
    BackStage bs;
    while (true) {
        int n;
        cin>>n;
        switch (n) {
            case 1:
                bs.showList();
                break;
            case 2:
                bs.addCommodity();
                break;
            case 3:
                bs.removeCommodity();
                break;
            case 4:
                cout<<bs.buy("cook", 20,500)<<endl;
                break;
            case 5:
                cout<<bs.getIncome()<<endl;
            default:
                break;
        }
    }
   
}
