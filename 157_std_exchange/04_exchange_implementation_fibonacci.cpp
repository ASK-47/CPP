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
   
    std::vector<int> numbers(17);   

    auto l_gen = [current = 0, next=1]() mutable {
        return current=std::exchange(
            next,
            current + next);  // result == current, start == current + step
    };

    std::generate(numbers.begin(), numbers.end(), l_gen);
    print(numbers);
}