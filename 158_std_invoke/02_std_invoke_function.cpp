//https://t.me/cplusplus_tg/2591
//std::invoke_result
#include <iostream>
#include <type_traits>

int add (int a, int b) {
    return a+b;
}

float add1 (float a, float b) {
    return a+b;
}

int main() {
    using result_type=std::invoke_result<decltype(add), int, int>::type;
    result_type x=add(42, 10500);
    printf("%d\n",x);

    using result_type1=std::invoke_result<decltype(add1), float, float>::type;
    result_type1 y=add1(3.14f, 0.0010500f);
    printf("%f\n",y);
}