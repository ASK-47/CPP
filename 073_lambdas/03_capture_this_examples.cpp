// https://t.me/grokaemcpp/787
// capture 'this' == ref/ptr => dangling ref/ptr


#include <iostream>

struct Foo {
    int m_x = 0;

    void func() {
        int x = 100500;
        // Explicit capture 'this'
        [this]() { /*access m_x and x*/ }();

        // Implcit capture 'this'
        [&]() { /*access m_x and x*/ }();//implicit capture 'this' by ref

        // Redundant 'this' (redundant but possible befor  C++20)
        [&, this]() { /*access m_x and x*/ }();

        // Implcit capture 'this'
        [=]() { /*access m_x and x*/ }();//capture 'this' by ref!!! Warning for C++20

        // Error before C++20, OK for C++20 - capture 'this' by value
        [=, this]() {}();

        std::cout << x;
    }
};

int main() {
    Foo f;
    f.func();
}