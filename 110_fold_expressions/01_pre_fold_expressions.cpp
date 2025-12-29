//https://youtu.be/nhk8pF_SlTk
//pre_fold_expressions
#include <iostream>

//C++14
template<typename... T>
auto sum (T...t) {
    
    //determines the common type (e.g., int if all are int, double if mixed) and initializes result to its default value (0 for numeric types)
    typename std::common_type<T...>::type result{};

    //Summation Trick 
    //Pre-C++17, there were no fold expressions (e.g., (t + ...) for binary folds).
    //This was a standard idiom (e.g., from Stack Overflow hacks) to achieve fold-like behavior for accumulation.

    //variadic Ctor for initializer_list => result+=t and returning 0 for each position    
    //cast the list to (void) to avoid warnings about unused variables 
    (void)std::initializer_list<int>{(result+=t, 0)...};
    
    return result;
}

int main() {
    std::cout << sum (1, 2, 3, 4, 5, 6, 7, 8, 9 ) <<'\n';    
}