//https://youtu.be/VpqwCDSfgz0?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//concepts_generic_variadic_lambdas
#include <iostream>
#include <concepts>

void lambda() {
    auto l =[][[nodiscard]](std::floating_point auto... x) noexcept -> float {
         return (x + ...);
    };       
    //l(1, 2, 3, 4, 5);//ERROR ignoring return value of 'lambda()::<lambda(auto:6 ...)> 
    std::cout << "l(1.1f, 2.2f, 3.3f, 4.4f, 5.5f) = " << l(1.1f, 2.2f, 3.3f, 4.4f, 5.5f) << std::endl;
}

struct Lambda {    
    template<std::floating_point ... T>
    [[nodiscard]] constexpr auto operator() (T...x) const noexcept-> float {
        return (x + ...);
    };
};

void equvalent () {
    auto l=Lambda{};    
    std::cout << "Lambda(1.1f, 2.2f, 3.3f, 4.4f, 5.5f) = " << l(1.1f, 2.2f, 3.3f, 4.4f, 5.5f) << std::endl;
}


int main() {
    lambda();
    equvalent ();  
}
