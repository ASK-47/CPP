#include <iostream>
#include <vector>
#include <print>
#include <ranges>


std::vector<int> Process(const std::string& str) {
    std::vector<int> result;
    for(const auto& s:str) {
        result.push_back(s);
    }
    return result;
};

int main () {
    std::vector<std::string> elems = {"a","b","c","d","e","f","g","h","j","k"};

    auto result = elems | std::views::transform([](const std::string &str) {
                return Process(str);
                }) | std::views::join | std::ranges::to<std::vector>();
    std::print("{}", result);    
}
