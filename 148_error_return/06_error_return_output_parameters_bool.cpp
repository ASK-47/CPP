//Old practice. Output параметры. Возвращаем enum успешности операции, а сам результат возвращаем в одном или нескольких выходных параметрах.
//https://t.me/grokaemcpp/916

#include <iostream>

bool parse_coordinates(const std::string& input, double& x, double& y, double& z, std::string& error_message) {
	return 1;
};

int main() {
    double x=10.5, y=20.3, z=30.7;
	std::string input {"10.5,20.3,30.7"};
	std::string error_msg{"Error"};
	if (parse_coordinates(input, x, y, z, error_msg)) {
		std::cout << "Coordinates: " << x << ", " << y << ", " << z << std::endl;		
	} else {
		std::cout << "Error: " << error_msg << std::endl;
	}
}