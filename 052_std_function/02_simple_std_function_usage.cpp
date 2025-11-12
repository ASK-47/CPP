#include <functional>
#include <iostream>

std::function<void(int, const std::string&)> my_func_object;
void f(int i, const std::string& s) {
    std::cout << s << ": " << i << std::endl;
}
int main() {
    my_func_object = f;
    my_func_object(10, "YES!!!");
}