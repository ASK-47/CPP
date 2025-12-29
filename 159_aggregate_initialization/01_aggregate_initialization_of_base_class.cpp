//https://youtu.be/qMqWoT016cA?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//aggregate_initialization
//C++17

#include <iostream>

struct B {
    int b=10500;
};

struct D:B {
    int x;
    float y;
};

int main() {
    D d {{}, 42, 3.14};
    printf ("d.b=%d\n", d.b);
}