//https://youtu.be/GeLp4F-Svc8?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//advanced_stateful_lambdas


#include <cstdio>
#include <memory>
#include <utility>

int main() {    
    auto unique_l = [a=0, b=std::make_unique<int>(42)] () mutable {
        return ++a;        
    };
    //auto l2=unique_l; ERROR

    auto non_unique_l = [a=0] () mutable {
        return ++a;        
    };    
    [[maybe_unused]]auto l2=non_unique_l;//OK
    
    auto l = [a=0, b=1] () mutable {
        struct Result {
            int& a;
            int& b;

            Result next(int num=1) {
                while (num>0) {
                    a=std::exchange(b, a+b);
                    --num;
                }                
                return *this;
            }

            operator int() {
                return a;
            }
        };
        return Result{a,b}.next();        
    };    

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

    return l().next(42);
}