//https://youtu.be/VpqwCDSfgz0?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//generic_lambdas
#include <iostream>

void lambda() {
    auto l =[](auto x, auto& y)-> long {
         return ++x + y++;
    };       
        // This won't work directly: 
        //long (*ftr)(int, int&) = l;  // Error: lambda type mismatch        
        int y = 15;        
        // Instead, use std::function or direct call
        std::cout << "Lambda direct call (int): " << l(10, y) << ", y: " << y << std::endl;
}

struct Lambda {
    template<typename T>    
    using fptr = long (*)(T, int&);

    template<typename T>
    constexpr static auto FUNC(T x, int& y) -> long {
        return ++x + y++;
    }
    
    //A conversion operator that returns FUNC as a function pointer when the struct is converted (implicitly or explicitly).
    template<typename T>
    constexpr auto operator()(T x, int& y) -> long {
        return ++x + y++;
    };

    template<typename T>
    constexpr operator fptr<T>() const { return FUNC<T>; };//no convertion => no Lambda usage as fpt   

};

void equvalent () {
    auto l=Lambda{};
    long (*ftr) (int , int&)=l;
    int y = 15;
    std::cout << "ftr direct call (int): " << ftr(10, y) << ", y: " << y << std::endl;    
}


int main() {
    lambda();
    equvalent ();  
}
