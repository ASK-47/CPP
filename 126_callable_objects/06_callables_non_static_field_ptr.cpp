// https://t.me/grokaemcpp/726
// callables_non_static_field_ptr

#include <iostream>
#include <functional>

struct Payment {
  double amount;
  std::string category;
};

int main() {    
    Payment p{100500, "confetki"};
    std::cout << std::invoke(&Payment::amount, p) << "=>" << std::invoke(&Payment::category, p)<<std::endl;
}