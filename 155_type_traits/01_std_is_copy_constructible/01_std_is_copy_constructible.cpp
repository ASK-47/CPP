// https://www.geeksforgeeks.org/cpp/stdis_copy_constructible-in-c-with-examples/
// std::is_copy_constructible

#include <bits/stdc++.h>
#include <type_traits>

struct B {
    B(const B&)=delete;
};

struct A {    
    A& operator=(A&) = delete;
};


int main() {
    std::cout << std::boolalpha;
    // Check that if char is copy constructible or not
    std::cout << "char: " << std::is_copy_constructible<char>::value << '\n';

    // Check that if int is copy constructible or not
    std::cout << "int: " << std::is_copy_constructible<int>::value << '\n';

    // Check that if int[2] is copy constructible or not
    std::cout << "int[2]: " << std::is_copy_constructible<int[2]>::value << '\n';

    // Check that if struct A is copy constructible or not
    std::cout << "struct A: " << std::is_copy_constructible<A>::value << '\n';

    // Check that if struct B is copy constructible or not
    std::cout << "struct B: " << std::is_copy_constructible<B>::value << '\n';

    return 0;
}