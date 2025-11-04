//Old practice. Output параметры. Возвращаем enum успешности операции, а сам результат возвращаем в одном или нескольких выходных параметрах.
//https://t.me/grokaemcpp/916

#include <iostream>
#include <cmath>

enum Code {
    Success,
    DivisionByZero,
    NegativeNumber,
    Overflow
};

Code safe_sqrt(double x, double& result) {
    if (x < 0) {
        return Code::NegativeNumber;
    }
    result = std::sqrt(x);
    return Code::Success;
}

int main() {
    double result = 0.0;
	auto code = safe_sqrt(-4.0, result);
	if (code != Code::Success) {
		//process_error(code)
		switch (code) {
			case Success: std::cout << "Success" << std::endl;
			break;
			case DivisionByZero: std::cout << "DivisionByZero" << std::endl;
			break;
			case NegativeNumber: std::cout << "NegativeNumber" << std::endl;
			break;
			case Overflow: std::cout << "Overflow" << std::endl;
			break;
			//default: std::cout << "Unknown Type"; break;
		}		
	} else {
	  std::cout << "Result: " << result << std::endl;
	}
}