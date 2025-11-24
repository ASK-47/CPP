// https://t.me/grokaemcpp/939
// std::underlying_type

#include <iostream>
#include <cstdint>
#include <utility>//c++23 std::to_underlying

enum class ColorMask : std::uint32_t {
    red = 0xFF,
    green = (red << 8),
    blue = (green << 8),
    alpha = (blue << 8)
};


//std::underlying_type, который предоставляет зависимый тип type, содержащий подкапотный тип enum'a:
enum e1 {};
enum class e2 {};
enum class e3 : unsigned {};
enum class e4 : int {};

constexpr bool e1_t = std::is_same_v<std::underlying_type_t<e1>, int>;
constexpr bool e2_t = std::is_same_v<std::underlying_type_t<e2>, int>;
constexpr bool e3_t = std::is_same_v<std::underlying_type_t<e3>, int>;
constexpr bool e4_t = std::is_same_v<std::underlying_type_t<e4>, int>;

int main() {
    std::cout << "underlying type for 'e1' is " << (e1_t ? "int" : "non-int")
              << '\n'
              << "underlying type for 'e2' is " << (e2_t ? "int" : "non-int")
              << '\n'
              << "underlying type for 'e3' is " << (e3_t ? "int" : "non-int")
              << '\n'
              << "underlying type for 'e4' is " << (e4_t ? "int" : "non-int")
              << '\n';

    // std::cout << ColorMask::red << std::endl; // ERROR =>    
    //static_cast<int>
    std::cout << static_cast<int>(ColorMask::red) << std::endl;

    //static_cast<std::underlying_type_t<>>
    std::cout << static_cast<std::underlying_type_t<ColorMask>>(ColorMask::red)<< '\n';
    
    //-std=c++23 -Wpedantic -Wall -Wextra -Wconversion -O3 -Werror
    std::cout << std::to_underlying(ColorMask::red) << '\n';
}