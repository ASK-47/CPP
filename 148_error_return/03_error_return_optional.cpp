//Good practice. Возврат ошибки. std::optional
//https://t.me/grokaemcpp/912

#include <iostream>
#include <optional>

struct Error {
    std::string message;
};

std::optional<double> safe_divide(double a, double b) {
    if (b == 0.0) { // здесь нужна нормальная проверка на равенство с epsilon
        return std::nullopt;
    }
    return a / b;
}



int main() {
    auto div_result = safe_divide(10.0, 0.0);

	if (div_result.has_value()) {//Checks whether *this contains a value
		std::cout << "Result: " << div_result.value() << std::endl;
	} else {
		std::cout << "Error: there is no value" << std::endl;
	}
	/* или с операторами
	if (div_result) { // operator bool
		std::cout << "Result: " << *div_result << std::endl; // operator*
	} else {
		std::cout << "Error: there is no value" << std::endl;
	}
	*/
}