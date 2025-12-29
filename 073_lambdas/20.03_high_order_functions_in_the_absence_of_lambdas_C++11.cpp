//https://youtu.be/VEqOOKU8RjQ?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//high_order_functions_in_the_absence_of_lambda

#include <iostream>

//C++17
auto add =[](const auto& lhs, const auto& rhs) {
    return lhs+rhs;
};
//C++11
struct Add {    
    template<typename LHS, typename RHS>
    auto operator() (const LHS& lhs, const RHS& rhs) const ->decltype (lhs +rhs) {//no auto => Traling RT
        return lhs +rhs;
    }
};
//C++17
auto lazy =[] (const auto& func, const auto& lhs, const auto& rhs) {
    return [func, lhs, rhs](){return func(lhs, rhs);};
};
//C++11
struct Lazy {        
    template<typename F, typename LHS, typename RHS>
    struct Inner {
        F func_;
        LHS lhs_;
        RHS rhs_;
        auto operator() () const -> decltype(func_(lhs_, rhs_)) {//no auto => Traling RT
            return func_(lhs_, rhs_);
        };    
    };    
    
    template<typename F, typename LHS, typename RHS>
    Inner<F, LHS, RHS> operator() (const F& func, const LHS& lhs, const RHS& rhs) {                
        return Inner{func, lhs, rhs};
    }
};

int main(const int argc, const char*[]) {    
    //C++17
    auto l1 =lazy(add, argc, 41);    
    std::cout << l1() << '\n';

    //C++17
    auto l2 =Lazy{}(Add{}, argc, 41);
    std::cout << l2() << '\n';

}