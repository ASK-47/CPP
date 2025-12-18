//https://youtu.be/br4tez2G9eM
//what_is_lambdas

#include <typeinfo>
#include <cstdio>

struct __main__lambda_0 {
    int val;
    template<typename T>
    constexpr auto operator() /*const*/(T i) {//if not mutable
        return 5+i+val;
    }
};

int main() {
    int val=10;
    auto l = [val](auto i) mutable {return 5+i+val;};
    puts(typeid(l).name());//Z4mainEUlT_E_
    return l(3);
}