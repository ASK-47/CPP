//td::set s{std::move(comparator)};  
//transparent_lambda_comparators


#include <string>
#include <set>
#include <type_traits>  // For std::decay_t

struct Data {
    std::string s;
};
//!!!heterogeneous lookups (e.g., searching with a key type different from Data, like a string).


//helper function to create set with comparator
/*template <typename Type, typename Comparator>
auto make_set (Comparator&& comparator) {
    return std::set<Type, std::decay_t<Comparator>>{std::forward<Comparator>(comparator)};
}*/

// Helper function to create a set with a combined comparator supporting heterogeneous comparisons
template <typename Type, typename... Comparator>
auto make_set (Comparator&& ...comparator) {
    struct Compare : std::decay_t<Comparator>... {
        using std::decay_t<Comparator>::operator()...;// This enables overloaded comparisons        
        // AI Fix: Use the standard way to make the comparator transparent for heterogeneous lookup
        using is_transparent = int;//is_transparent = void; (a standard C++ idiom).
    };
    return std::set<Type, Compare>{Compare{std::forward<Comparator>(comparator)...}};    
}


int main() {
    auto comparator =[](const Data& lhs, const Data& rhs){
        return lhs.s<rhs.s;
    };    
    //C++20
    //std::set<Data, decltype(comparator)> set;
    
    //OR with CTAD
    //std::set s{std::move(comparator)};  
    
    //C++17 (move for not copieble lambda)
    std::set<Data, decltype(comparator)> s{std::move(comparator)};

    auto set = make_set<Data>(
        // Data-Data comparison
        [](const Data& lhs, const Data& rhs) { return lhs.s < rhs.s; },
        // Heterogeneous: string-like-Data (e.g., for lower_bound or count with string keys)
        [](const auto& lhs, const Data& rhs) { return lhs < rhs.s; },
        // Heterogeneous: Data-string-like (e.g., for upper_bound or count)
        [](const Data& lhs, const auto& rhs) { return lhs.s < rhs; }
    );

    set.count("Bob");
    //showcases heterogeneous lookup. 
    //Since the lambdas accept auto (e.g., const auto& lhs),
    //it can compare a const char* (from "Bob") against Data or other types, relying on std::string's comparison operators.
    //The count will be 0 here because no elements are inserted into the set.

}