//https://youtu.be/DolVujl_EUw?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//lambda_to_function_pointer_conversion_C_API

#include <iostream>
#include <vector>

//1 C-function usess *fptr as argument => we can convert lambda to *ftr
extern "C" {
    void callback (int(*)(int));
}
// => we can convert lambda to *ftr to usr C-function
void f () {
    callback([](int i) {return i+2;});
}

//2 Convinient to use for func call at place
void g () {
    std::vector<int(*)(int, int)> v;
    v.push_back([](int i, int j) {return i+j;});
    v.push_back([](int i, int j) {return i*j;});
}

int main() {    
}