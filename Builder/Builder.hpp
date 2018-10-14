//
//  Builder.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/14.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Builder_hpp
#define Builder_hpp
#include <iostream>
//定义产品
struct Computer{
    std::string cpu;
    std::string gpu;
    std::string ram;
    std::string brand;
    
};
//Director
class Builder{
    std::string cpu;
    std::string gpu;
    std::string ram;
    std::string brand;
public:
    Builder& setCpu(const std::string &c){
        cpu=c;
        return *this;
    }
    Builder& setGpu(const std::string &g){
        gpu=g;
        return *this;
    }
    Builder& setRam(const std::string &r){
        ram=r;
        return *this;
    }
    Builder& setBrand(const std::string &b){
        brand=b;
        return *this;
    }
    
    Computer GetResult(){
        return Computer{cpu,gpu,ram,brand};
    }
    
};
class ComputerShop{
    Builder builder_;
public:
    explicit ComputerShop(const Builder&b):builder_(b){}
    Computer Construct(){
        return builder_.GetResult();
    }
    
    
};

#endif /* Builder_hpp */
