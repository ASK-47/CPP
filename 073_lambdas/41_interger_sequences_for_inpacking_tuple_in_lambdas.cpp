//https://youtu.be/VpqwCDSfgz0?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//tuple_and_interger_sequences_for_lambdas
//C++17
#include <iostream>
#include <concepts>
#include <utility>
#include <tuple>

void lambda() {
    auto sum_tuple =[] <typename...T>(const std::tuple<T...>& input) {
         return []<std::size_t...Idx>(std::index_sequence<Idx...>, const auto& tuple) {
            return (std::get<Idx>(tuple)+...);
         } (std::make_index_sequence<sizeof...(T)>(), input);//sizeof...(T) - позволяет определить количество элементов в пакете
    };
    //std::make_index_sequence<10>()) correctly creates std::index_sequence<0,1,2,3,4,5,6,7,8,9>
    //l(std::make_index_sequence<10>()) sums to 45 (0+9=45).     
    std::cout << "sum_tuple (1, 2ll, 3l, 4.5) = " <<
        sum_tuple(std::make_tuple(1, 2ll, 3l, 4.5)) << std::endl;
}

struct Lambda {    
    struct Lambda_{    
        template<std::size_t  ... Idx, typename Tuple>
        constexpr auto operator() (std::index_sequence<Idx...>, const Tuple& tuple) {
            return (std::get<Idx>(tuple) + ...);
        }
    };
    template<typename... T>
    constexpr auto operator() (const std::tuple<T...>& input) {
        return Lambda_{}(std::make_index_sequence<sizeof...(T)>(), input);
    }
};

void equvalent () {
    auto l=Lambda{};    
    std::cout << "Lambda(std::make_tuple(1, 2ll, 3l, 4.5)) = (0+...+9) = " << l(std::make_tuple(1, 2ll, 3l, 4.5)) << std::endl;
}

int main() {
    lambda();
    equvalent ();  
}