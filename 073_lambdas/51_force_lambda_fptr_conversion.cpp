//https://youtu.be/b3fFxneoHso?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//force_lambda_fptr_conversion (positive_lambda_hack)

#include <iostream>

int main() {
    auto succeeded = [](){return false;};

    //[-Werror=address] fol ptr to bool conversion
    /*if (succeeded!=nullptr) {
        std::cout << "Succeeded" << '\n';
    } else  {
        std::cout << "Failed" << '\n';
    }*/    
    std::cout << reinterpret_cast<void*>(+succeeded) << '\n';//+ to force conversion to the function pointer

    //The + operator (unary plus) when applied to a lambda (or any object with an implicit conversion to a function pointer)
    //forces the conversion to the function pointer type. So +succeeded yields bool(*)()

}
