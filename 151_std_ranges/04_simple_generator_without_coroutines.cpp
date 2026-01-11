//https://youtu.be/F37h3FuA8kM?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//simple_generator_without_coroutines

#include <iostream>
#include <utility>
#include <ranges>

auto generator (auto func) {
    return std::views::iota(0) | std::views::transform(func);
    //return infinite sequence (std::views::iota(0)) where each element is transformed by applying func
};

int main() {
    auto fibo = [i=0, j=1](auto) mutable {//lambda ignores its input parameter (the auto from the generator)
        return i=std::exchange(j, i+j);
    };

    for (const auto val : generator(fibo) | std::views::take(20)) {//creates a view that generates the first 20 Fibonacci values
        std::cout << val << '\n';
    }    
}