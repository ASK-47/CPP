//Good practice. Возврат ошибки. std::variant
//https://t.me/grokaemcpp/909

#include <iostream>
#include <variant>

struct Error {
    std::string message;
};

std::variant<double, Error> safe_divide(double a, double b) {
    if (b == 0.0) {
        return Error{std::string{"Division by zero"}};
    }
    return a / b;
}

int main() {
    auto div_result = safe_divide(10.0, 0.0);
    if (std::holds_alternative<double>(div_result)) {//std::holds_alternative возвращается true , если существует вариант.
    std::cout << "Result: " << std::get<double>(div_result) << std::endl;
    } else {
    std::cout << "Error: " << std::get<Error>(div_result).message << std::endl;
    }
}