//https://youtu.be/qMGi_tdKrrk?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//lambdas_on_the_heap_for_unmovable_lambda

#include <array>
#include <memory>

auto make_lambda() {
    struct S {
        S(S&& s) =delete; //unmovable lambda
        S(const S& s) =delete; //uncopible lambda
        S() =default;
        int x=42; 
    };
    
    //auto l = [s=S{}] () {return s.x;};//error: capture == move of unmovable object - use of deleted function   
    //return l;
    
    //return [s=S{}] () {return s.x;};//RVO

    //OK, but memory leak!!!
    auto l = new auto ([s=S{}] () {return s.x;});//auto - new sintax
    //return (*l)();

    //Avoiding memory leak
    std::unique_ptr<std::remove_cvref_t<decltype(*l)>> ptr{l};
    return (*ptr)();

}

int main() {
    return make_lambda();
}