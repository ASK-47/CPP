//https://youtu.be/3wm5QzdddYc?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//visitor_from_lambdas

//-std=c++23 -Wpedantic -Wall -Wextra -Wconversion -O3 -Werror

#include <iostream>
#include <variant>
#include <array>
#include <algorithm>

template<typename... L>
struct Visitor : L... {
    template<typename... T>
    Visitor(T&&...t) : L(std::forward<T>(t))...  {}
    using L::operator()...;    
};

template<typename...T>
Visitor(T...)->Visitor<std::decay_t<T>...>;


int main() {
    std::array<std::variant<double, int, char, std::string>, 10> var{
        3.2, 2, 3.8, 4, 5, 6, 8.3, 7.7, 9.1, 11.1}; 
    int total_int=0;
    double total_double=0.0;
    Visitor visitor {
        [&total_int](const int i){total_int+=i;},
        [&total_double](const double d){total_double+=d;},
	    [](const auto&){}//to fix error with std::string	
    };

    std::for_each(begin(var), end(var),
        [&visitor](const auto &v){std::visit(visitor,v);} );

        printf("total_int= %d\n", total_int);
        printf("total_double= %.1f\n", total_double);
}
