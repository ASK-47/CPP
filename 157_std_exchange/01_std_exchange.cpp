//https://t.me/cpp_geek/347
//std::exchange

#include <utility>
#include <string>
#include <iostream>

// A <= B <=C <=> A==B B==C
// auto A = std::exchange(B, C);

//Полезно при реализация move-конструкторов/операторов:
 template <typename T>
 struct MyType {
    T data;
    MyType(MyType&& other) : data(std::exchange(other.data, nullptr)) {}
 }; 

struct S {
    int n;
 
    S(S&& other) noexcept : n{std::exchange(other.n, 0)} {} 
    S& operator=(S&& other) noexcept {
        n = std::exchange(other.n, 0); // Move n, while leaving zero in other.n
        // Note: in case of self-move-assignment, n is unchanged
        // Also note: if n is an opaque resource handle that requires
        //            special cleanup, the resource is leaked.
        return *this;
    }
};

int main() {
  
    
    std::string s = "Hello";
    auto old = std::exchange(s, "World");    

    std::cout << "old = " << old << ", s = " << s << '\n';
}
