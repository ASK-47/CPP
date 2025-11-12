//Ep 506 - Zero Cost Function Binding
//https://youtu.be/9laCL5GixNk


#include <functional>
#include <iostream>

void print(const std::string& first, const std::string& second) {
    std::cout << first << ": " << second << "\n";
}

void print_plural(const std::string& first, const std::string& second, const std::string& third) {
    std::cout << first << ": " << second << third << "\n";
}

// possible implementation
// since c++26
template <auto Func, typename... Param>//Func - callable thing
constexpr auto bind_front(Param&&... param) {//lambda capture set of param and insert it as first set of values into Func
    return [... param = std::forward<Param>(param)]<typename... Inner>(Inner&&...inner) {return Func(param..., std::forward<Inner>(inner)...); };
}


int main() {
    auto b1_front = std::bind_front(print, "Example N1");
    b1_front("10500");
    b1_front("10500100");

    // since c++26
    const auto b2_front = std::bind_front<print>("Example N2");
    b2_front("10500");
    b2_front("10500100");

    // possible implementation
    auto b3_front = bind_front<print>("Example N3");
    b3_front("10500");
    b3_front("10500100");

    //bind one first parameter "Example N4"
    auto b4_front = bind_front<print_plural>("Example N4");
    b4_front("10500", " 200100");

    //bind two first parameters "Example N5", "XXXX "
    auto b5_front = bind_front<print_plural>("Example N5", "XXXX ");
    b5_front("10500");
   
}