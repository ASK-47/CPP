//https://t.me/cpp_geek/349
//LOG_macros

#include <iostream>

#define LOG(var) std::cout << #var << " = " << (var) << std::endl;

int main() {
    int x = 42;
    double pi = 3.1415;

    LOG(x);   // x = 42
    LOG(pi);  // pi = 3.1415
}
