//AI ChatGPT 5.1
//std_get__examples

#include <iostream>
#include <utility>
#include <tuple>
#include <array>
#include <variant>

int main() {
    //std::pair
    std::pair<int, std::string> p = {42, "hello"};
    std::cout << std::get<0>(p) << std::endl;  // Output: 42 (first element)
    std::cout << std::get<1>(p) << std::endl;  // Output: hello (second element)

    //std::tuple
    std::tuple<int, double, std::string> t = {1, 2.5, "world"};
    std::cout << std::get<0>(t) << std::endl;     // Output: 1 (int)
    std::cout << std::get<1>(t) << std::endl;     // Output: 2.5 (double)
    std::cout << std::get<2>(t) << std::endl;     // Output: world (string)
    // Alternative: by type (if types are unique)
    std::cout << std::get<double>(t) << std::endl;  // Output: 2.5
    

    //std::array
    std::array<int, 3> arr = {10, 20, 30};
    std::cout << std::get<0>(arr) << std::endl;  // Output: 10
    std::cout << std::get<1>(arr) << std::endl;  // Output: 20
    std::cout << std::get<2>(arr) << std::endl;  // Output: 30
    //Modify second element
    std::get<1>(arr) = 99;  
    std::cout << std::get<1>(arr) << std::endl;  // Output: 99

    //C++17
    [[maybe_unused]]auto [a, b] = std::pair{1, 2};  // Internally uses std::get

    //std::variant
    std::variant< int, std::string > var;
    var = {"WTF"};
    visit([](auto&& e) {std::cout << e << '\n';}, var );
    std::cout << std::get<std::string>(var) << std::endl;
}