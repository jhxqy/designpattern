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
template<typename T,typename=void>
struct HasOperatorB:public std::false_type{

};
template<typename T>
struct HasOperatorB<T,std::void_t<decltype(std::declval<T>().OperatorB())>>:public std::true_type{

};
template<typename T,typename=void>
struct HasOperatorC:public std::false_type{

};
template<typename T>
struct HasOperatorC<T,std::void_t<decltype(std::declval<T>().OperatorC())>>:public std::true_type{

};
template<typename Impl>
class InterFace{
    Impl body;
    template<typename U,typename=typename std::enable_if<HasOperatorA<U>::value>::type>
    void _OperatorA(){
        body.OperatorA();
    }
    template<typename U,typename=typename std::enable_if<HasOperatorB<U>::value>::type>
    void _OperatorB(){
        body.OperatorB();
    }
    
    template<typename U,typename=typename std::enable_if<HasOperatorC<U>::value>::type>
    void _OperatorC(){
        body.OperatorC();
    }
    
    
public:
    void OperatorA(){
        this->_OperatorA<Impl>();
    }
    void OperatorB(){
        this->_OperatorB<Impl>();
        this->_OperatorC<Impl>();
    }
//    template<typename =std::enable_if_t<HasOperatorB<Impl>::value>,typename =std::enable_if_t<HasOperatorC<Impl>::value>>
//    void OperatorB(){
//        body.OperatorB();
//        body.OperatorC();
//    }
    
};

#endif /* Bridge_h */
