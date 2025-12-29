//https://youtu.be/1gNzhE-Tn40
//inheriting_from_lambdas_variadic
#include <iostream>
#include <functional>
#include <type_traits>

template<typename... B>
struct Merged : B... {
    template<typename... T>
    Merged(T&&...t) : B(std::forward<T>(t))...
    {        
    }
    using B::operator()...;    
};

template<typename...T>  //to fix Merged<L> + <T> inside
Merged(T...)->Merged<std::decay_t<T>...>;
//User-defined deduction guides
//https://en.cppreference.com/w/cpp/language/class_template_argument_deduction.html

//template<typename... T>: This declares a variadic template guide that can accept any number of template parameters.
//Merged(T...) -> Merged<std::decay_t<T>...>: This specifies that when you construct a Merged object with arguments of types T... (e.g., Merged(obj1, obj2)),
//the compiler should deduce the template parameter as Merged<std::decay_t<decltype(obj1)>, std::decay_t<decltype(obj2)>, ...>.
//std::decay_t<T> removes references, const/volatile qualifiers, and arrays from T, effectively "decaying" it to a prvalue type (similar to pass-by-value semantics)
//This is useful for storing types without worrying about referenceness.

int main() {
    auto l1= [](){return 42;};
    auto l2= [](const int i){return i*10;};

    
    Merged m1 (l1, l2);

    std::cout<< m1() <<'\n';
    std::cout<< m1 (10500) <<'\n';


    Merged m2 (l1, l2, [](const double d){return d*3.14;});

    std::cout<< m2() <<'\n';
    std::cout<< m2 (10500) <<'\n';
    std::cout<< m2 (3.1418) <<'\n';
}