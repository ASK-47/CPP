//capture_by_ref_murable_lambda

#include <iostream>

int main() {
    std::string s{"abcd"};
    std::string sub{"bc"};

    //auto lambda = [&sub] (const std::string& str)  { OK - changing ref
    //auto lambda = [sub] (const std::string& str)  { ERROR - changing field by operator() const => need mutable
    auto lambda = [sub] (const std::string& str) mutable {
        std::cout<< sub << '\n';    
        sub+='e';
        std::cout<< sub << '\n';    
        return str.find(sub)!=std::string::npos;
    };

    std::boolalpha(std::cout);
    std::cout<< lambda(s) << '\n';
    std::cout<< sub << '\n';        
}