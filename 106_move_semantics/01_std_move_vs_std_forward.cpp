//https://t.me/cpp_geek/349
//std::move vs std::forward

#include <utility>
#include <string>
#include <iostream>

void process(const std::string& s) { std::cout << "Lvalue: " << s << '\n'; }
void process(std::string&& s) { std::cout << "Rvalue: " << s << '\n'; }

template <typename T>
void wrapper(T&& arg) {
    process(std::forward<T>(arg)); // сохраняет rvalue/lvalue-семантику
}

int main() {
    std::string str = "Hello";
    wrapper(str);               // Lvalue
    wrapper(std::move(str));    // Rvalue
}
