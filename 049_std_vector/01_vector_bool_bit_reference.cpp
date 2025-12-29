//https://t.me/cpp_ready/1797
//bit_reference

#include <iostream>
#include <vector>

int main() {
    std::vector<bool>v{true, false};
  	std::cout << "v[0]=" <<v[0]<< '\n';;  
  	auto x= v[0];// x is a _Bit_reference (proxy object) => x==ref(v[0])
    auto y=bool(v[0]);// y is a copy
  	std::cout << "x=" << x << '\n';
    std::cout << "y=" << y << '\n';
    
    y= false; 
    std::cout << "y=" << y << '\n';
    std::cout << "v[copy y=0]=" <<v[0]<< '\n';

    x= false; //v[0] is changed, sice x==ref(v[0])
    std::cout << "x=" << x << '\n';
    std::cout << "v[ref x=0]=" <<v[0]<< '\n';    
}