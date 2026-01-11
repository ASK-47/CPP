//https://youtu.be/fZe7gNgjV4A?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//fibonacci_lambda
#include <iostream>
#include <utility>  //for std::exchange

int main() {  
    auto fib = [current = 0, next=1]() mutable {
        return current=std::exchange(next,current + next);
    };
    std::cout << fib() << '\n';
    std::cout << fib() << '\n';
    std::cout << fib() << '\n';
    std::cout << fib() << '\n';
    std::cout << fib() << '\n';
    std::cout << fib() << '\n';
}