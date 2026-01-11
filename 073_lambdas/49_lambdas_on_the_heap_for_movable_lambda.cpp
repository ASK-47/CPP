//https://youtu.be/W4G2xJX9Gnw?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//lambdas_on_the_heap_for_movable_lambda

#include <array>
#include <memory>

struct Lambda {
    std::array<int, 1024> d{};
    constexpr int operator() () {
        return d[5];
    }
};

int main() {
    //auto l= new decltype([](){return 42;}); 
    //return (*l)();
    
    /*auto big_lambda= [d=std::array<int,1024>{}]() {
        return d[5];
    }; 
    return sizeof(big_lambda);*/

    //error: use of deleted function 'main()::<lambda()>::<lambda>()'
    ///auto big_lambda= new decltype([d=std::array<int,1024>{}]() {return d[5];} );     

    //Memory leak!!!
    /*auto big_lambda= [d=std::array<int,1024>{}]() {return d[5]; }; 
    auto l1= new decltype(big_lambda)(std::move(big_lambda)); 
    return (*l1)();*/

    auto l2 =std::make_unique<Lambda>();
    return (*l2)();    

}