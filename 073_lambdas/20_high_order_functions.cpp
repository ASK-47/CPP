//https://youtu.be/NoIJoL3cIJ4?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//high_order_functions

#include <utility>

template <typename F, typename G> 
auto f_of_g (F&& f, G&& g) {
    return [f=std::forward<F>(f), g=std::forward<G>(g)] () {return f(g());};
}

int expansive_calculation (int) {return 42;};
int even_more_expansive_calculation() {return 10500;};

int main(const int argc, const char*[]) {
    //expamsive_calculation(even_more_expamsive_calculation)   
    auto calculate = f_of_g(expansive_calculation, even_more_expansive_calculation);    

    if(argc>17) {
        return calculate();
    }
}