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

double safe_sqrt(double x, Code& code) {
    if (x < 0) {
        code = Code::NegativeNumber;
        return {};
    }
    code = Code::Success;
    return std::sqrt(x);
}

int main() {
    Code code = Code::Success;    
	auto result = safe_sqrt(-4.0, code);
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