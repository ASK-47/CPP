// https://t.me/grokaemcpp/726
// callables_non_static_method

#include <iostream>

struct Handler {
  void foo(int a) {
    std::cout << "Non-static method: " << a << std::endl;
  }
};

int main() {    
    Handler{}.foo(42);

}