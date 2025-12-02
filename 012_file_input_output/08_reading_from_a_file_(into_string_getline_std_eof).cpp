//https://cppscripts.com/eof-cpp
//std::eof()

#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("example.txt");
    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}