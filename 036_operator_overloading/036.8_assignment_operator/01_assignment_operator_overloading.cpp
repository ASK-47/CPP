// https://t.me/easy_c_plus/1824
// assignment_operator_overloading

#include <iostream>

class MyClass {
   public:
    int value;
    MyClass(int v) : value(v) {}

    MyClass& operator=(const MyClass& other) {
        if (this != &other) {  // Защита от самоприсваивания
            value = other.value;
        }
        return *this;
    }
};

int main() {
    MyClass a(1), b(2), c(3);
    a = b = c;  // Работает, потому что `b = c` возвращает ссылку на `b`
    std::cout << "a: " << a.value << ", b: " << b.value << ", c: " << c.value << std::endl;
}
