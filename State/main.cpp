//
//  main.cpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/11/3.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <stdio.h>
#include "State.hpp"
using namespace std;
int main(){
    VendingMachine vm;

    while (true) {
        cout<<"1.投币"<<endl<<"2.选择"<<endl<<"3.结束购物"<<endl;

        cout<<"请输入选择:";
        int n;
        cin>>n;
        switch (n) {
            case 1:
                vm.CoinOperated();
                break;
            case 2:
                vm.choose();
                break;
            case 3:
                vm.end();
                break;
            default:
                break;
        }
    }
    
}
