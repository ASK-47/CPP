//https://youtu.be/GeLp4F-Svc8?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//fibonacci_lambda

#include <cstdio>
#include <memory>
#include <utility>

struct Fibo {
    int n0=0;
    int n1=1;
    constexpr int operator () () /*const*/   {
        int old=n1;
        n1+=n0;
        n0=old;        
        return n0;
    }
};

int main() {   
    
    auto fibo=[a=0, b=1] () mutable {
        a=std::exchange(b, a+b);       
        return a;
    };    

    printf("fibo= %d\n", fibo());
    printf("fibo= %d\n", fibo());
    printf("fibo= %d\n", fibo());
    printf("fibo= %d\n", fibo());
    printf("fibo= %d\n", fibo());
    printf("fibo= %d\n", fibo());

    Fibo f;
    printf("f= %d\n", f());
    printf("f= %d\n", f());
    printf("f= %d\n", f());
    printf("f= %d\n", f());
    printf("f= %d\n", f());
    printf("f= %d\n", f());    
}