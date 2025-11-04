//Bad practice. Возврат ошибки. Кастомная структура
//https://t.me/grokaemcpp/908

#include <iostream>

template<typename T>
struct Result {
    T value;
    std::string error;

    static Result ok(T val) {
        return Result{std::move(val), {}};
    }
  
    static Result fail(std::string err_msg) {
        return Result{T{}, std::move(err_msg)};
    }

   operator bool() const { return error.empty(); }
};

Result<double> safe_divide(double a, double b) {
    if (b == 0.0) {
        return Result<double>::fail("Division by zero");
    }
    return Result<double>::ok(a / b);
}



int main() {
    auto div_result = safe_divide(10.0, 0.0);
    if (div_result) {
    std::cout << "Result: " << div_result.value << std::endl;
    } else {
    std::cout << "Error: " << div_result.error << std::endl;
    }
}