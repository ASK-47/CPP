// https://t.me/cpp_ready/1674
// std::erase, std::erase_if C++20
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template <typename T>
void print_v(const std::vector<T>& v) {
    for (auto& e : v) {
        printf(" %d\n", e);
    }
}

template <typename K, typename V>
void print_m(const std::map<K, V>& m) {
    for (auto [key, value] : m) {
        printf(" %s ", key.c_str());
        printf(" %d\n", value);
    }
}

int main() {
    std::string s = "std::erase, std::erase_if";

    std::erase(s, ':');
    std::puts(s.c_str());
    printf("string= %s\n", s.c_str());

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_v(v);

    std::erase_if(v, [](int x) { return x % 2 != 0; });
    print_v(v);

    std::map<std::string, int> m = {
        {"Alice", 10}, {"Bob", 0}, {"Eve", 5}, {"Tom", 0}};
    print_m(m);

    std::erase_if(m, [](const auto& item) {
        const auto& [key, value] = item;
        return value == 0;
    });
    print_m(m);
}