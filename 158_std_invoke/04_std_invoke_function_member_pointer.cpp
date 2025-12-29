//https://youtu.be/z-kUhwANrIw
//std_invoke_function_member_pointer
#include <iostream>
#include <functional>

int f(const int i) {
    return i+5;
}

struct S  {
    int i=5;
    int f(const int j) {
        return i+j;
    }
    int g(const int j) {
        return i+j;
    }
};


int main() {    
    //std::invoke is waiting for: pointer + object + arg
    //0
    std::cout<< std::invoke(f, 37) <<'\n';
    std::cout<< std::invoke(&f, 37) <<'\n';
    std::cout<< std::invoke(&S::f, S{}, 37) <<'\n';//S{} is needed!!
    //1
    auto f_ptr=&S::f;    
    std::cout<< S{}.f(37) <<'\n';//S{} is needed!!   
    std::cout<< std::invoke(f_ptr, S{}, 37) <<'\n';//S{} is needed!!
    //2
    int(S::*f_ptr2)(int)=&S::f;
    std::cout<< (S{}.*f_ptr2)(37) <<'\n';//S{} is needed!!
    std::cout<< std::invoke(f_ptr2, S{}, 37) <<'\n';//S{} is needed!!
    //3
    int(S::*f_ptr3)(int)=nullptr;
    if(true) {
        f_ptr3=&S::g;
    } else {
        f_ptr3=&S::f;
    }   
    std::cout<< (S{}.*f_ptr3)(10500) <<'\n';//S{} is needed!!
    std::cout<< std::invoke(f_ptr3, S{}, 10500) <<'\n';//S{} is needed!!
     //4 member field invoke
    std::cout<< std::invoke(&S::i, S{}) <<'\n';//S{} is needed!!
}