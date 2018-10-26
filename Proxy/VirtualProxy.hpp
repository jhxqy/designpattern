//
//  VirtualProxy.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2018/10/26.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef VirtualProxy_hpp
#define VirtualProxy_hpp

#include <stdio.h>
#include <iostream>
//一个创建开销非常大的对象;
class BigClass{
    //具体参数之类
    int n;
public:
    BigClass(int n){
        //有很大的开销
        std::cout<<"创建了巨大开销的对象"<<std::endl;
    }
};

class BigClassProxy{
    int n;
    BigClass *p=nullptr;
public:
    BigClassProxy(int nn):n(nn){}
    int f(){
        // 获取参数之类的代码;
        return n;
    }
    
    void write(){
        if(p==nullptr){
            p=new BigClass(n);
        }
        //对p操作
        std::cout<<"操作了p;"<<std::endl;
    }
};


#endif /* VirtualProxy_hpp */
