//https://youtu.be/VpqwCDSfgz0
//for_each

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>//for std::ref

std::vector<int>  get_data() {
    return std::vector<int>  {10, 9, 8, 7, 6, 4, 3, 2, 1, 0};
}

auto l = [i=0](int x) mutable {
        std::cout << '[' << i << "]="<< x <<' ';
};

int main() {    
    std::ranges::for_each(get_data(), l);
    std::cout << '\n';
    std::ranges::for_each(get_data(), std::ref(l));
}
