// https://t.me/grokaemcpp/924
#include <iostream>

// Во вчерашнем посте мы рассказывали об особом типе указателя - pointer to data
// member. Этот указатель, которым и является p из примера, по сути хранит
// информацию о том, как в объекте найти нужное поле класса. И в большинстве
// случаев эта информация представляет собой просто смещение поля относительно
// начала объекта в байтах. Однако нулевое смещение используется для локации
// самого первого поля класса. Поэтому в байтовом представлении
// неинициализированный указатель не может быть нулем.

struct A {
    int i;
};

struct Type {
    double a;
    char b;
    float c;
    long long d;
    short e;
    unsigned f;
};

int main() {
    int A::* p = 0;
    // Однако нулевое смещение используется для локации самого первого поля
    // класса. Поэтому в байтовом представлении неинициализированный указатель
    // не может быть нулем
    std::cout << std::boolalpha << (p == nullptr) << "\n";
    std::cout
        << std::hex << std::bit_cast<std::uintptr_t>(p)
        << "\n";  // Вместо этого обычно используется число -1, которое в
                  // байтовом представлении как раз выглядит как все единички:

    std::cout << std::hex << static_cast<long long int>(-1) << "\n";

    std::cout << std::boolalpha
              << (std::bit_cast<std::uintptr_t>(p) == 0xffffffffffffffff)
              << "\n";

    // С помощью указателей на поля класса можно кстати наглядно изучать
    // выравнивание и упаковку полей с объект:
    std::cout << std::dec << std::bit_cast<std::uintptr_t>(&Type::a) << "\n";
    std::cout << std::dec << std::bit_cast<std::uintptr_t>(&Type::b) << "\n";
    std::cout << std::dec << std::bit_cast<std::uintptr_t>(&Type::c) << "\n";
    std::cout << std::dec << std::bit_cast<std::uintptr_t>(&Type::d) << "\n";
    std::cout << std::dec << std::bit_cast<std::uintptr_t>(&Type::e) << "\n";
    std::cout << std::dec << std::bit_cast<std::uintptr_t>(&Type::f) << "\n";
}
