// https://t.me/grokaemcpp/728
// exchange implementation

#include <algorithm>
#include <iostream>
#include <utility>  //for std::exchange
#include <vector>

template <class T, class U = T>
constexpr T exchange(T& obj, U&& new_value) {
    T old_value = std::move(obj);
    obj = std::forward<U>(new_value);
    return old_value;
}

template <typename T>
void print(const std::vector<T>& vec) {
    for (const auto& v : vec) std::cout << v << '\t';
    std::cout << '\n';
}

int main() {
   
    std::vector<int> numbers(23);
    print(numbers);

    int start = 5;
    int step = 2;

    auto l_gen = [current = start, step]() mutable {
        return std::exchange(
            current,
            current + step*step);  // result == current, start == current + step
    };

    std::generate(numbers.begin(), numbers.end(), l_gen);
    print(numbers);
}