//https://youtu.be/VpqwCDSfgz0?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//operator_fptr_conversion
#include <iostream>

struct Lambda {
    typedef long (*fptr)(int, int&);

    constexpr static auto FUNC(int x, int& y) -> long {
        return ++x + y++;
    }
    //A conversion operator that returns FUNC as a function pointer when the struct is converted (implicitly or explicitly).
    constexpr auto operator()(int x, int& y) -> long {
        return ++x + y++;
    };

    constexpr operator fptr() const { return FUNC; };//no convertion => no Lambda usage as fpt 
};

// A function that expects a function pointer
long apply_func(Lambda::fptr fp, int a, int& b) {
    return fp(a, b) * 2;  // Calls the function pointer and doubles the result
}

int main() {
    Lambda l{};
    int x = 10, y = 15;

    //Example: Use operator fptr() implicitly when passing to a function
    //Lambda => Lambda::fptr
    long result = apply_func(l, x, y);  // 'l' converts to fptr via operator fptr()
    std::cout << "Result from function: " << result << ", x: " << x << ", y: " << y << std::endl;

    // This is equivalent to explicitly calling the operator:
    // Lambda::fptr fp = l;  // Implicit conversion
    // result = apply_func(fp, x, y);

    return 0;
}
