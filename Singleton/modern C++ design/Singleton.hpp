//
//  Singleton.hpp
//  Singleton
//
//  Created by 贾皓翔 on 2018/12/22.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef Singleton_hpp
#define Singleton_hpp
#include <mutex>
#include <stdio.h>
template<typename T>
class SingleThreaded{
    std::mutex m;
public:
    typedef T VolatileType;
    typedef std::lock_guard<std::mutex> Lock;
    
};
template<typename T>
class NormalCreation{
public:
    
};
template
<
    typename T,
    template<typename>class CreationPolicy,
    template<typename>class LifetimePolicy,
    template<typename>class ThreadingModel=SingleThreaded
>
class SingletonHolder{
    
};

#endif /* Singleton_hpp */
