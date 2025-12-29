//https://youtu.be/fLeHy7s1WIo?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//bind_front_implemented_with_lambdas

#include <iostream>

template<typename Function, typename...Parameters>
auto bind_front (Function&& f, Parameters&& ...p) {
    return [f=std::forward<Function>(f), ...bound_p= std::forward<Parameters>(p)]
        (auto&& ...p) ->decltype(auto) {//for perfect returning
         return f(bound_p..., std::forward<decltype(p)>(p)...);
    };
}


int add(int a, int b, int c) {
    return a+b+c;
}

int main() {
    std::cout << add(1, 2, 3) <<'\n';
    auto f= bind_front(&add, 2, 3);
    std::cout <<  f(42) << '\n';
    
}