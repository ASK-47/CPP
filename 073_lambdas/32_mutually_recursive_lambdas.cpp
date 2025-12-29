//https://youtu.be/9L9uSHrJA08?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//mutually_recursive_lambdas
#include <iostream>
#include <cstdio>

constexpr auto fibo=[](const auto fibo,  int n) {
    if(n<2) return n;
    return fibo(fibo, n-1) + fibo(fibo, n-2);   
};

//=> we can make a helper - main
constexpr auto fib=[](int n) {    
    return fibo(fibo, n);   
};

//=> put lambda directly inside fib
constexpr auto f=[](int n) {    
    auto fibo=[](const auto fibo,  int n) {
        if(n<2) return n;
    return fibo(fibo, n-1) + fibo(fibo, n-2);
    };
    return fibo(fibo, n);
};

//=>f1 and f2 separation 
//mutually recursive functions
auto f1=[](const auto f1, const auto f2, int n) {
    if(n<2) return n;
    return f2(f1, f2, n-1) + f1(f1, f2, n-2);   
};

auto f2=[](const auto f1, const auto f2,  int n) {
    if(n<2) return n;
    return f1(f1, f2, n-1) +f1(f1, f2, n-2);   
};

int main() {
    std::cout << fibo(fibo, 10) <<'\n';
    //=> we can make a helper - line 12
    std::cout << fib(10) <<'\n';
    //=> put lambda directly inside fib  
    std::cout << f(10) <<'\n'; 

    //=>f1 and f2 separation
    std::cout << f1(f1, f2, 10) <<'\n';
}