// https://t.me/cplusplus_tg/130
// NDEBUG_macros

#define NDEBUG// if NOT defined NDEBUG => DEBUG ONLY
#include <iostream>

void foo(int x) {
#ifndef NDEBUG
    std::cerr << "x = " << x << "\n";// for debug only
#endif
    std::cout << x*x <<'\n';
}

#ifdef NDEBUG
#define DEBUG(var)  // for debug only
#else
#define DEBUG(var)                                \
    {                                             \
        std::cout << #var << ": " << var << '\n'; \
    }
#endif

#ifndef NDEBUG
    #define DBG_LOG(msg) std::cerr << msg << "\n"
#else
    #define DBG_LOG(msg) ((void)0)
#endif


int main() {
    [[maybe_unused]]int x{10500};    

    DEBUG(x);
    foo(42);
    DBG_LOG("ERROR");

    //ONLY if NOT #define NDEBUG   
    //Program stderr
    //x = 42
    //ERROR
}
