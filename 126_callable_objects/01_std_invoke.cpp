#include <iostream>
#include <functional>

struct P {
    void print () {
        std::cout << "Print \n";
    }
};

int main() {
    P p;
    std::invoke(&P::print, &p); 

    auto l = [](int x){return x*x;};
    std::cout << std::invoke(l, 5); 
}