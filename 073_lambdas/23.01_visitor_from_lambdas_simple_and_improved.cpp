//https://youtu.be/EsUmnLgz8QY?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//visitor_from_lambdas_simple_and_improved
#include <iostream>
#include <variant>
#include <algorithm>

template<typename... Base>
struct Visitor : Base... {
    //Ctor is not needed for C++17, since aggregate initialisation
    //template<typename... T>
    //constexpr  Visitor(T&&...t) noexcept((std::is_nothrow_constructible_v<Base>&&...)): Base(std::forward<T>(t))...  {}
    
    using Base::operator()...;    
};

template<typename...T>
//No need sicnce CTAD
//Visitor(T...)->Visitor<std::decay_t<T>...>;
Visitor(T...)->Visitor<T...>; 


int main() {
    
    constexpr auto v1 = std::variant<int, double> {6.28};
    constexpr auto v2 = std::variant<int, double> {3};

    constexpr Visitor visitor {
        []( int i)->double {return i+0.14;},
        [](double d)->double {return d-3.14;}
    };
        printf("visit v1= %.2f\n", std::visit(visitor, v1)); 
        printf("visit v2= %.2f\n", std::visit(visitor, v2)); 
}
