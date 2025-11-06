//#include <iostream>
#include <fstream>

int main () {
    std::ofstream os("foo.txt");
    if(os.is_open()) {
        os << "Hello World!";
    }
}