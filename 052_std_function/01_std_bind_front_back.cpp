//https://t.me/cplusplus_tg/3036

#include <functional>
#include <iostream>

void print(const std::string& first, const std::string& second) {
    std::cout << first << ": " << second << "\n";
}

int main() {
    auto b_front = std::bind_front(print, "Example N");
    b_front("10500");
    b_front("10500100");

    auto b_back = std::bind_back(print, "is example number");
    b_back("10500");
    b_back("10500100");
}