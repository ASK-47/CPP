// https://t.me/grokaemcpp/726
// callables_non_static_method_ptr

#include <iostream>
#include <functional>

struct Handler {
  void foo(int a) {
    std::cout << "Non-static method: " << a << std::endl;
  }
};

int main() {    
    auto non_static_method_ptr = &Handler::foo;
    std::invoke(non_static_method_ptr, Handler{}, 42);    
    
    //std::invoke(Handler::foo, Handler{}, 42);//Error
}