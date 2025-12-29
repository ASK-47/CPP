//https://youtu.be/UwYYc5dpvqk?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//parameter_packs_in_captures_C20

//-std=c++23 -Wpedantic -Wall -Wextra -Wconversion -O3 -Werror

#include <utility>//for std::move

template <typename Callable, typename...Param>
auto bind_varibles(Callable f, Param...p) {
    //return [=](){// = - capture f and p... by copy - BAD
    return [f=std::move(f), ...p=std::move(p)](){// = - capture f/p.... by move
        return f(p...);
    };
}

int add(int lhs, int rhs) {
    return lhs + rhs;
}

int main() {
    const auto bound = bind_varibles(add, 1, 2);//make a 2 copy of param for add
    //lazy, untill call
    return bound(); 

}