//https://t.me/grokaemcpp/938
//enum size
//https://dzen.ru/a/aSMExRRDQzo4SShc

#include <iostream>
enum MY_FAVOURITE_FRUITS {
    E_APPLE = 0x01,
    E_WATERMELON = 0x02,
    E_COCONUT = 0x04,
    E_STRAWBERRY = 0x08,
    E_CHERRY = 0x10,
    E_PINEAPPLE = 0x20,
    E_BANANA = 0x40,
    E_MANGO = 0x80,
    E_MY_FAVOURITE_FRUITS_FORCE8 =
        0xFF  // 'Force' 8bits, how can you tell? 0xFF == 11111111 == 255
};

enum class E_MY_FAVOURITE_FRUITS : unsigned char {
    E_APPLE = 0x01,
    E_WATERMELON = 0x02,
    E_COCONUT = 0x04,
    E_STRAWBERRY = 0x08,
    E_CHERRY = 0x10,
    E_PINEAPPLE = 0x20,
    E_BANANA = 0x40,
    E_MANGO = 0x80,
    E_DEVIL_FRUIT = 0xFF
};

int main() {
    std::cout << sizeof(MY_FAVOURITE_FRUITS) << '\n';    // 4 bytes !!!
    std::cout << sizeof(E_MY_FAVOURITE_FRUITS) << '\n';  // 1 bytes !!!
}