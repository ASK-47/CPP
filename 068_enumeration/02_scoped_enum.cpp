// https://t.me/grokaemcpp/935
// enum class
#include <iostream>

// 1.1 enum - inplicit cast
enum eColor { RED, GREEN, BLUE };
eColor ec = RED;
// Color next = c + 1; //Error

// Обычные перечисления экспортируют свои перечислители в окружающую область
// видимости, вызывая конфликты имён с другими сущностями в этой окружающей
// области:
// enum TrafficLight { RED, YELLOW, GREEN }; // ERROR!

// 2.1 scoped enum - NO inplicit cast
enum class Color { RED, GREEN, BLUE };
Color c = Color::RED;
// cColor next = cc + 1; // ERROR!

// 2.2 Onli explicite cast
int next = static_cast<int>(c) + 1;                         // OK!
Color cnext = static_cast<Color>(static_cast<int>(c) + 1);  // OK!

// 2.3 НЕ экспортируют свои перечислители в окружающую область
// Имена перечислителей находятся в скоупе своего перечисления:
enum class Color1 { RED, GREEN, BLUE };
enum class Color2 { RED, GREEN, BLUE };

void graphics_library() {
    Color1 c1 = Color1::RED;
    Color2 c2 = Color2::RED;
}

int main() {}