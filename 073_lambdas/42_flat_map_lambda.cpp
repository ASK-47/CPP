//https://youtu.be/z5ndvveb2qM?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//flat_map_lambda

#include <iostream>
#include <vector>
#include <algorithm>

int main() {    
    auto flat_map
        =[data=std::vector<std::pair<int, int>>()]
        (int new_key) mutable -> auto& {
        for(auto& [key, value]: data) {
            if (key ==new_key) {
                return value;
            }
        }
        return data.emplace_back(new_key, 10500).second;
    };

    std::cout <<  flat_map(1) << '\n';    
    std::cout <<  flat_map(2) << '\n';
    
    flat_map(1)=42;    
    std::cout <<  flat_map(1) << '\n';    
    std::cout <<  flat_map(2) << '\n';
}
