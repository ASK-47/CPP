//https://youtu.be/BBUacofxOP8?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//transparen_comparators

#include <iostream>
#include <set>

struct Data {
    std::string key;
    std::string value;    
    
};

struct Comparator {    
    bool operator()(const Data & lhs, const Data & rhs) const {
        return lhs.key<rhs.key;
    }
    template<typename T>   
    bool operator()(const Data & lhs, const T & rhs) const {
        return lhs.key<rhs;
    }

    template<typename T>   
    bool operator()(const T & lhs, const Data & rhs) const {
        return lhs<rhs.key;
    }
    //Magic MF
    //Without is_transparent:
    //The container's find, count, lower_bound, etc., methods expect the search key to be of the same type as the elements stored. For example, if your std::set stores Data objects, you'd need to search with a Data instance.
    
    //With is_transparent:
    //The comparator is "transparent," meaning it accepts different types for comparison. The container can deduce the search type during lookup, enabling direct comparisons between stored elements and arbitrary key types (e.g., strings, pointers, or custom types).

    //is_transparent = int; enables transparent behavior
    using is_transparent = int;//догадайся сас с чем сравниваешь!!!
    //Without is_transparent and those templated operators, count("Bob") would fail to compile because the container expects a Data object for lookup.
};


int main() {
    std::set<Data, Comparator> s;
    s.insert(Data{"Bob"});
    return s.count("Bob");
}