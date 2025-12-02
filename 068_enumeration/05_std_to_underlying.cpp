//C++23
#include <iostream>
#include <utility>

enum class Color : bool { Red, Green };

int main() {
    Color color1 = Color::Red;
    Color color2 = Color::Green;
	
	std::cout << std::boolalpha;
    std::cout << "Underlying value of color1: " << std::to_underlying(color1) << '\n';
    std::cout << "Underlying value of color2: " << std::to_underlying(color2) << '\n';

    return 0;
}