//https://t.me/grokaemcpp/726
//std::exchange

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>//for std::exchange

class SequenceGenerator {
    int current;
    int step;

   public:
    SequenceGenerator(int start = 0, int step_size = 1)
        : current(start), step(step_size) {}

    // Оператор вызова без аргументов - возвращает следующее число
    int operator()() {
        int val = current;
        current += step;
        return val;
    }
};

template<typename T>
void print (const std::vector<T>& vec) {
    for(const auto& v:vec)
        std::cout << v << '\t';
    std::cout << '\n';
}


int main () {
    SequenceGenerator gen;
    std::vector<int> numbers(5);
    std::generate(numbers.begin(), numbers.end(), gen);  // заполняем вектор с помощью функтора
    print(numbers);

    int start = 5;
    int step = 2;
    
    auto l_gen = [current = start, step]() mutable {
        return std::exchange(current, current + step); // result == current, start == current + step
    };
    
    std::generate(numbers.begin(), numbers.end(), l_gen);
    print(numbers);
}