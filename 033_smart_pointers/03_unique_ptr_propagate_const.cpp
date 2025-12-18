//https://en.cppreference.com/w/cpp/experimental/propagate_const.html
//propagate_const
#include <experimental/propagate_const>
#include <iostream>
#include <memory>

struct X {
    void g() const { std::cout << "X::g (const)\n"; }
    void g() { std::cout << "X::g (non-const)\n"; }
};

struct Y {
    Y()
        : m_propConstX(std::make_unique<X>()),
          m_autoPtrX(std::make_unique<X>()) {}

    void f() const {
        std::cout << "Y::f (const)\n";
        m_propConstX->g();
        m_autoPtrX->g();
    }

    void f() {
        std::cout << "Y::f (non-const)\n";
        m_propConstX->g();
        m_autoPtrX->g();
    }

    std::experimental::propagate_const<std::unique_ptr<X>> m_propConstX;
    std::unique_ptr<X> m_autoPtrX;
};

int main() {
    Y y;
    y.f();

    const Y cy;
    cy.f();
}