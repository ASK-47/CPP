//https://youtu.be/NMWv2vQQjXE?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//pointers_to_overloaded_functions

// The goal is to create function taking all other overloadind functions as arg

#include <utility>//for std::forward

//1:: only fo 1 type
//void use_callable(void(*)(int));

//2::auto => static_cast<T>
void use_callable(auto){}

void callable(int) {};
void callable(double) {};


//3:: lambda-wrap
//use_callable([](auto v){return callable(v);});

//+template + forward
//auto use_callable3 ([]<typename T>(T&& t) ->decltype(auto) {
    //return callable(std::forward<T>(t));
    //}
//);

//+ MACROS
#define OVERLOAD(x) []<typename T>(T&& t) ->decltype(auto) \
    {return callable(std::forward<T>(t));}

int main() {

    //1::problems with overloading
    //use_callable(&callable); //ERROR
    
    //2::auto => static_cast<T>
    use_callable(static_cast<void(*)(int)>(&callable));
    use_callable(static_cast<void(*)(double)>(&callable));

    //3::lambda-wrap + +template + forward + MACROS
    use_callable(OVERLOAD(callable));    
}
