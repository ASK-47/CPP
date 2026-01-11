//https://youtu.be/HNn-PmrL5X8
//stupid_constexpr_tricks

#include <iostream>

constexpr auto make_val() { return 10; }

int main() {
    const auto x = 42; //constexpr
    const auto y = [](){return 43; }();//constexpr

    const auto result = [](){ return x + y + make_val(); }(); //return (constexpr + constexpr + constexpr) => result is constexpr
    
    static_assert(result == 95);

    return result;
}