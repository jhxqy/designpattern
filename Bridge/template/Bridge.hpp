//
//  Bridge.hpp
//  designpattern
//
//  Created by 贾皓翔 on 2019/10/5.
//  Copyright © 2019 贾皓翔. All rights reserved.
//

#ifndef Bridge_h
#define Bridge_h
#include <type_traits>

template<typename T,typename=void>
struct HasOperatorA:public std::false_type{
    
};
template<typename T>
struct HasOperatorA<T,std::void_t<decltype(std::declval<T>().OperatorA())>>:public std::true_type{
    
};
//template<typename T,typename=void>
//struct HasOperatorB:public std::false_type{
//
//};
//template<typename T>
//struct HasOperatorB<T,std::void_t<decltype(std::declval<T>().OperatorB())>>:public std::true_type{
//
//};
//template<typename T,typename=void>
//struct HasOperatorC:public std::false_type{
//
//};
//template<typename T>
//struct HasOperatorC<T,std::void_t<decltype(std::declval<T>().OperatorC())>>:public std::true_type{
//
//};
template<typename Impl>
class InterFace{
    Impl body;
public:
    void OperatorA(){
        body.OperatorA();
    }
    void OperatorB(){
        body.OperatorB();
        body.OperatorC();
    }
//    template<typename =std::enable_if_t<HasOperatorB<Impl>::value>,typename =std::enable_if_t<HasOperatorC<Impl>::value>>
//    void OperatorB(){
//        body.OperatorB();
//        body.OperatorC();
//    }
    
};

#endif /* Bridge_h */
