// https://t.me/cplusplus_tg/3046
// std::generator (C++23) позволяет создавать ленивые генераторы, которые
// вычисляют значения по требованию, аналогично yield в Python. Это удобно для
// обработки больших потоков данных без лишнего потребления памяти

#include <generator>
#include <iostream>

std::generator<int> fibonacci(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        co_yield a;
        int tmp = a;
        a = b;
        b = tmp + b;
    }
}

int main() {
    for (int n : fibonacci(42)) {
        std::cout << n << '\n';
    }
}
