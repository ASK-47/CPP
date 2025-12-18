//https://en.cppreference.com/w/cpp/memory/unique_ptr/release
//std::unique_ptr::release()
#include <cassert>
#include <iostream>
#include <memory>

struct Foo {
    Foo() { std::cout << "Foo\n"; }
    ~Foo() { std::cout << "~Foo\n"; }
};

// Ownership of the Foo resource is transferred when calling this function
void legacy_api(Foo* owning_foo) {
    std::cout << __func__ << '\n';
    // [legacy code that no one understands or dares touch anymore]
    // [...]
    delete owning_foo;
}

int main() {
    std::unique_ptr<Foo> managed_foo(new Foo);
    // [code that might return or throw or some such]
    // [...]
    legacy_api(managed_foo.release());

    assert(managed_foo == nullptr);
}