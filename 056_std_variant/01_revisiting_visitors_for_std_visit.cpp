//https://www.youtube.com/watch?v=et1fjd8X1ho&t=240s

#include <iostream>
#include <variant>
#include <string_view>

std::variant<int, float, std::string_view> get_variant()
{
  return 4.2f;
}


template<typename ... Callable>
struct visitor : Callable... {
  using Callable::operator()...;
};

int main() {
  const auto value = get_variant();
  std::visit(
    visitor{[](int i){std::cout << "Int: "<< i <<'\n';}, 
            [](float f){std::cout <<"Float: " << f <<'\n';},
            [](std::string_view sv){std::cout <<"SV: "<< sv <<'\n';}}
    , value);
	
	char a[]="abcd";
	std::cout << printf("%s", a) << '\n';	
}