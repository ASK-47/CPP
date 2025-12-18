//https://youtu.be/W-xTpqj31mI?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//inheriting_fromL_lambdas
#include <iostream>
#include <functional>
#include <type_traits>

template<typename L1, typename L2>
struct S : L1, L2 {
    S(L1 l1, L2 l2) : L1{std::move(l1)}, L2{std::move(l2)} {}
    using L1::operator();
    using L2::operator();
};

template<typename L1, typename L2>
auto make_combined (L1 &&l1 , L2 &&l2) {
    return S<std::decay_t<L1>, std::decay_t<L2>>(std::forward<L1>(l1), std::forward<L2>(l2));    
}

int main() {
    auto l1= [](){return 42;};
    auto l2= [](const int i){return i*10;};

    auto comb =make_combined(l1, l2);

    std::cout<< comb() <<'\n';
    std::cout<< comb(10500) <<'\n';
}