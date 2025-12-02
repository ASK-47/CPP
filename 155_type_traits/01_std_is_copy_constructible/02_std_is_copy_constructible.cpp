#include <iostream>
#include <type_traits>

class MyClass {
public:
    explicit MyClass(int num) : number(num) {}
    // Copy constructor
    MyClass(const MyClass& other) : number(other.number) {}

private:
    int number;
};

int main() {
    // Check if the type is copy constructible
    bool isCopyConstructible = std::is_copy_constructible<MyClass>::value;

    if (isCopyConstructible) {
        std::cout << "MyClass is copy constructible." << std::endl;
    } else {
        std::cout << "MyClass is not copy constructible." << std::endl;
    }

    return 0;
}