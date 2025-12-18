// https://t.me/grokaemcpp/726
// callables_function_object == no_captured_lampda

#include <iostream>

class FunctionObjectCast {
   public:
    using fun_ptr = int (*)(int);  // Оператор приведения к указателю на функцию

    operator fun_ptr() { return &staticMethod; }

    static int staticMethod(int x) {
        return x * 2;
    }  // Статический метод, который будет вызываться через указатель
};

int main() {
    FunctionObjectCast obj;
    obj(42);  // cast here
}