//https://youtu.be/3wm5QzdddYc?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//generic_visitor_from_lambdas

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
    std::array<std::variant<double, int>, 10> var{
        3.2, 2, 3.8, 4, 5, 6, 8.3, 7.7, 9.1, 11.1}; 
    
    int total_int=0;
    double total_double=0.0;
    std::common_type_t<decltype(total_int), decltype(total_double)> total_common=0;    

    Visitor visitor {
        [&total_int, &total_common](const int i){total_int+=i; total_common+=i;},
        [&total_double, &total_common](const double d){total_double+=d; total_common+=d;},        	    
    };

    auto generic_visitor = [&total_int, &total_double, &total_common](const auto v) {
        total_common += v;  // Always add to common (as double)
        if constexpr (std::is_same_v<double, decltype(v)>) {
            total_double += v;
        }  else if constexpr (std::is_integral_v<decltype(v)>){  // Assumes int (or other arithmetic types, but array is only int/double)
            total_int += v;
        }
    };

    std::for_each(begin(var), end(var),
        [&visitor](const auto &v){std::visit(visitor,v);} );

    printf("total_int= %d\n", total_int);
    printf("total_double= %.1f\n", total_double);
    printf("total_common= %.1f\n", total_common);

    std::for_each(begin(var), end(var),
        [&generic_visitor](const auto &v){std::visit(generic_visitor,v);});

    printf("total_int= %d\n", total_int);
    printf("total_double= %.1f\n", total_double);
    printf("total_common= %.1f\n", total_common);
}