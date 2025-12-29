//https://youtu.be/z_fnMdzfWAQ
//variadic_min

#include <iostream>
#include <algorithm>

int min_1 (int x, int y, int z) {
    return std::min(std::min(x,y),z);
}

int min_2 (int x, int y, int z) {
    return std::min({x,y,z});//init list is generated == array => overhead if no optimozation (for g++)
}

//reason to create variadic min
template <typename F, typename ...T>
decltype(auto) min_variadic (const F&f, const T&...t) {
    const F *ret_val=&f;
    ((ret_val=&std::min(*ret_val, t)),...);
    return *ret_val;
}

int min_3 (int x, int y, int z) {
    return min_variadic(x,y,z);
}

int main() {
    
}
