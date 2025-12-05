// https://t.me/cpp_ready/1693
// цикл в линейный конвейер;

#include <iostream>
#include <list>
#include <ranges>
#include <vector>

//One conveyer => diffrent data structures
auto make_pipe_line() {
    return std::views::filter([](int x) { return x % 2 == 0; }) |
           std::views::transform([](int x) { return x * x; });
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::list<int> l{10, 12, 23, 14, 15, 66, 71, 86, 95, 60, 101, 122};

    auto e = v | std::views::filter([](int x) { return x % 2 == 0; });
    for (int r : e) {
        std::cout << r << '\t';
    }
    std::cout << '\n';

    auto rng = v | std::views::filter([](int x) { return x % 2 == 0; }) |
               std::views::transform([](int x) { return x * x; }) |
               std::views::take(5);

    for (int r : rng) {
        std::cout << r << '\t';
    }
    std::cout << '\n';

    
    //One conveyer => diffrent data structures    
    auto pipe = make_pipe_line();
    for (int x : v | pipe) {
        std::cout << x << '\t';
    }
    for (int x : l | pipe) {
        std::cout << x << '\t';
    }
}
