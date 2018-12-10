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
#include "Machine.hpp"
using namespace std;
int main(){
    Machine m;
    while (true) {
        cout<<"欢迎使用自动售货机"<<endl;
        cout<<"1.投币"<<endl;;
        cout<<"2.挑选物品"<<endl;
        cout<<"3.退币"<<endl;
        cout<<"4.进入后台"<<endl;
        cout<<"5.退出"<<endl;
        cout<<"请输入：";
        int n;
        cin>>n;
        switch (n) {
            case 1:
                m.CoinOperated();
                break;
            case 2:
                m.choose();
                break;
            case 3:
                m.end();
                break;
            case 4:
                m.enterBackStage();
                break;
            case 5:
                return 0;
                break;
            default:
                break;
        }
    }
    
   
}
