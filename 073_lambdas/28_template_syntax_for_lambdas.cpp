//https://youtu.be/ixGiE4-1GA8?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//template_syntax_for_lambdas

#include <cstdio>
#include <vector>

int main() {
    auto l = [](auto a, auto b){return a+b;};
    printf("l= %.2f\n", l(1.14,2.0));

    //using templates C++20
    //auto lambda = []<typename T>(T a, T b)-> auto {return a+b;};    
    //return lambda(2.1, 4); //ERROR    
    
    auto lambda = []<typename T>(const std::vector<T> & v, [[maybe_unused]] auto s) {return v.size();};    
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7};

    printf("v.size= %.ld\n", lambda(v, "WTF"));    
}