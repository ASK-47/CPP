//https://youtu.be/z5ndvveb2qM?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//flat_map_variadic_lambda

#include <iostream>
#include <vector>
#include <algorithm>


int main() {    
    auto flat_map
        =[my_map_type=[](){// initialization capture
            struct My_Type{};
            return My_Type{};
        }(),//to involke => my_map_type is initialized with a default-constructed My_Type object (essentially an empty, placeholder type).       
        data=std::vector<std::pair<int, int>>()]
        (auto&&...new_key) mutable -> auto& {
        if constexpr (sizeof ... (new_key) ==1) {
            for(auto& item: data) {
                if (item.first ==(new_key, ...)) {
                    return item.second;
                }
            }
            return data.emplace_back((new_key, ...), 10500).second;
        } else {
            return data;
        }        
    };

    std::cout <<  flat_map(1) << '\n';    
    std::cout <<  flat_map(2) << '\n';
    
    flat_map(1)=42;    
    std::cout <<  flat_map(1) << '\n';    
    std::cout <<  flat_map(2) << '\n';

    flat_map(2)=100;
    std::cout <<  flat_map(1) << '\n';    
    std::cout <<  flat_map(2) << '\n';

    flat_map(3)=1000;
    flat_map(4)=10000;
    flat_map(5)=100000;

    for(const auto& [key, value]: flat_map()) {
        std::cout << key << ' ' << value << '\n';
    }
}
