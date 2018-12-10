//
//  Backstage.hpp
//  machine
//
//  Created by 贾皓翔 on 2018/12/10.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Backstage_hpp
#define Backstage_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <utility>

class Machine;
struct Commodity{
    int number;
    int price;
    Commodity(int n,int p):number(n),price(p){}
};
class BackStage{
    std::map<std::string,Commodity> commoditys_;
    int income_;
    void addCommodity();
    void removeCommodity();
    int getIncome() const;
    void openOrClose(bool,Machine &m);
public:
    BackStage();
    void showList() const;
    int buy(const std::string &,int,int);
    void enterBS(Machine *m);
    ~BackStage();
};


inline int BackStage::getIncome() const{
    return income_;
}
#endif /* Backstage_hpp */
