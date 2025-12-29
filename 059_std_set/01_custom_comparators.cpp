//https://youtu.be/sbiF1HDcG7U?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//custom_comparators

#include <iostream>
#include <set>

struct Data {
    std::string key;
    std::string value;    
    //bool operator<(const Data & rhs) const {
        //return key<rhs.key;
    //}   
};

struct Comparator {    
    bool operator()(const Data & lhs, const Data & rhs) const {
        return lhs.key<rhs.key;
    }   
};


int main() {
    std::set<Data, Comparator> s;
    s.insert(Data{"Bob"});
}