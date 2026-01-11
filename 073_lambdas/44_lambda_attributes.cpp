//https://youtu.be/YlmxNJnone0?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//lambda_attributes
//C++23

#include <functional>

int main() {

    auto l = [i = 42] [[nodiscard]] () [[deprecated]] { return 42; };
    //[[nodiscard]].
    //Compilers may warn if you call l() without using its return value (e.g., in l();).

    //[[deprecated]]
    //Compilers may emit warnings when the lambda is used (e.g., during calls or assignments), encouraging avoidance.    

    using lambda_type = decltype(l);//type of the lambda

    using t = decltype(&lambda_type::operator());
    // type of the lambda's operator()
    //Result is a member function pointer type, like int (lambda_type::*)() const

    //std::function<std::remove_pointer_t<t>> f; //ERROR

    //std::function expects a callable signature like R(Args...). 
    //Passing a member function pointer type is invalid
    //std::function doesn't directly support member pointers unless you bind them to an object (e.g., using std::bind).
    
}