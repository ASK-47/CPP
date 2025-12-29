//https://youtu.be/VEqOOKU8RjQ?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//high_order_functions_in_the_absence_of_lambda

#include <iostream>

//C++17
auto add =[](const auto& lhs, const auto& rhs) {
    return lhs+rhs;
};
//C++11
struct Add {    
    template<typename Param>
    Param operator() (const Param& lhs, const Param& rhs) const {//no auto  no Traling RT
        return lhs +rhs;
    }
    //helper to evaluate return type
    template<typename LHS,typename RHS>
    struct Return_Type {
        typedef LHS type;//now type==LHS
    };
};

//C++17
auto lazy =[] (const auto& func, const auto& lhs, const auto& rhs) {
    return [func, lhs, rhs](){return func(lhs, rhs);};
};
//C++98
struct Lazy {        
    template<typename F, typename LHS, typename RHS>
    struct Inner {
        F func_;
        LHS lhs_;
        RHS rhs_;

        //C++98 no agreggate initialization
        Inner(const F& func, const LHS& lhs, const RHS& rhs)
            : func_(func), lhs_(lhs), rhs_(rhs) {}


        typename F::template Return_Type<LHS, RHS>::type operator() () const{//no auto /no Traling RT
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

    //C++98 -no auto //no decltype// no Traling RT //no agreggate initialization
    return Lazy()(Add(), argc, 41)();

}