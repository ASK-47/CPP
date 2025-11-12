// https://t.me/cpp_ready/1558
// nodiscard
#include <iostream>
#include <optional>

[[nodiscard]] std::optional<int> parse_sum(std::string_view s) {
    return s == "42" ? std::optional{42} : std::nullopt;
}

int main() {
    //Компилятор предупредит, если возвращаемое значение не используют
    // parse_sum("42");//ignoring return value of 'std::optional<int>
    // parse_sum(std::string_view)', declared with attribute 'nodiscard'
    // [-Wunused-result]
    if (auto n = parse_sum("42")) {
        std::cout << *n << '\n';
    }
    //or
    std::cout << *parse_sum("42") << '\n';
}