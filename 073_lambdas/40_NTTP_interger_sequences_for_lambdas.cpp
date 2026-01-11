//https://youtu.be/VpqwCDSfgz0?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//NTTP_interger_sequences_for_lambdas
//C++17
#include <iostream>
#include <concepts>
#include <utility>

void lambda() {
    auto l =[] <std::size_t ...Idx>(std::index_sequence<Idx...>) noexcept -> long {// Idx... are compile-time size_t values from 0 to N-1
         return (Idx + ...);
    };
    //std::make_index_sequence<10>()) correctly creates std::index_sequence<0,1,2,3,4,5,6,7,8,9>
    //l(std::make_index_sequence<10>()) sums to 45 (0+9=45).     
    std::cout << "l(std::make_index_sequence<10>()) = (0+...+9) = " << l(std::make_index_sequence<10>()) << std::endl;
}

struct Lambda {    
    template<std::size_t  ... Idx>
    constexpr auto operator() (std::index_sequence<Idx...>) const noexcept-> float {
        return (Idx + ...);
    }
};

void equvalent () {
    auto l=Lambda{};    
    std::cout << "Lambda(std::make_index_sequence<10>()) = (0+...+9) = " << l(std::make_index_sequence<10>()) << std::endl;
}

int main() {
    lambda();
    equvalent ();  
}