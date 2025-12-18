// https://t.me/grokaemcpp/726
// callables_lampda

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

void print (const std::vector<int>& vec) {
    for(int v:vec) 
    printf("%d ", v);
    printf("\n");
}

int main() {
    int start = 5;
    int step = 2;

    auto gen = [current = start, step]() mutable {
        return std::exchange(current, current + step);
    };

    std::vector<int> numbers(50);
    std::generate(numbers.begin(), numbers.end(), gen);

    print(numbers);
}