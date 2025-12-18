//https://t.me/cplusplus_tg/3048
//emplace_hint

#include <iostream>
#include <unordered_map>

void print (std::unordered_map<std::string, int>& data) {
    for(const auto& [key, value]: data) {
        std::cout << key << ' ' << value <<'\n';
    }
}


int main() {
    std::unordered_map<std::string, int> data;
    auto hint = data.end();
    
    data.emplace_hint(hint, "Alice", 25);        
    data.emplace_hint(hint, "Bob", 30);    

    print (data);
}