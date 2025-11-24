// https://t.me/cplusplus_tg/3012
// std::monostate из заголовка <variant> используется как «пустой» тип внутри
// std::variant. Это полезно для добавления незначимого состояния, которое можно
// обработать отдельно

#include <iostream>
#include <variant>

int main() {
    std::variant<std::monostate, int, std::string> data;
    auto visitor = [](auto value) {
        if constexpr (std::is_same_v<decltype(value), std::monostate>) {
            std::cout << "Void state (monostate)" << '\n';
        } else {
            std::cout << "Value=" << value << '\n';
        }
    };

    std::visit(visitor, data);  // Void state (monostate)

    data = 42;
    std::visit(visitor, data);  // Value=42

    data = std::string("String");
    std::visit(visitor, data);  // Value=String
}