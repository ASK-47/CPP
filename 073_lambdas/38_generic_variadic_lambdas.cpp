//https://youtu.be/VpqwCDSfgz0?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//generic_variadic_lambdas
#include <iostream>

void lambda() {
    auto l =[][[nodiscard]](auto... x) noexcept -> long {
         return (x + ...);
    };       
    //l(1, 2, 3, 4, 5);//ERROR ignoring return value of 'lambda()::<lambda(auto:6 ...)> 
    std::cout << "l(1, 2, 3, 4, 5) = " << l(1, 2, 3, 4, 5) << std::endl;
}

struct Lambda {    
    template<typename... T>
    constexpr auto operator() (T...x) const noexcept-> long {
        return (x + ...);
    };
};

void equvalent () {
    auto l=Lambda{};    
    std::cout << "Lambda(1, 2, 3, 4, 5) = " << l(1, 2, 3, 4, 5) << std::endl;
}


int main() {
    lambda();
    equvalent ();  
}
