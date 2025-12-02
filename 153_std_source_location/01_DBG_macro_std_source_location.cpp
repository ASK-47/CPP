//https://t.me/cpp_ready/1679
//DBG-макрос на std::source_location: удобно дебажим выражения с контекстом

#include <iostream>
#include <source_location>//since C++20
#include <string_view>
#include <vector>

#ifndef NDEBUG
#define DBG(expr) debug_print((expr), #expr)//Параметр макроса можно превратить в строку, добавив перед ним знак '#'
#else
#define DBG(expr) ((void)0)
#endif

template <typename T>
void debug_print(
    const T& value, std::string_view expr,
    const std::source_location& loc = std::source_location::current()) {
    std::cerr << "[DBG] " << expr << " = " << value << "\n"
              << "  at " << loc.file_name() << ":" << loc.line() << " in "
              << loc.function_name() << "\n";
}

int main() {
    int x = 42;
    std::vector<int> v{1, 2, 3};

    DBG(x);
    DBG(v.size());
    DBG(v[1] + x);

    return 0;
}