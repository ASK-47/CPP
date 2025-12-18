//https://youtu.be/dvLKY-oWqn0?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//lambda_to_function_pointer_conversion

#include <iostream>
#include <set>

struct Person {
    std::string name;
};


int main() {
    
    auto l = [](const Person& lhs, const Person& rhs){return lhs.name < rhs.name;};
    
    //using fptr = bool(*)(const Person& lhs, const Person& rhs);
    typedef bool(*fptr)(const Person& lhs, const Person& rhs);

    [[maybe_unused]]fptr myFP=l;

    std::set<Person, fptr> s {std::move(l)};
    //or
    //std::set<Person, fptr> s { [](const Person& lhs, const Person& rhs){return lhs.name < rhs.name;}};
}