//https://youtu.be/dvLKY-oWqn0?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//lambdas_as_comparators

#include <iostream>
#include <set>

struct Lifetime {
    Lifetime() noexcept {  std::cout <<"Lifetime() [default constructor]\n"; }
    
    ~Lifetime() noexcept { std::cout <<"~Lifetime() [destructor]\n"; }
    
    Lifetime(const std::string& s)  noexcept  : key(s) {
        std::cout <<"Lifetime(const std::string &) [parametric constructor]\n";
    }    
    
    Lifetime(const Lifetime&) noexcept {
        std::cout <<"Lifetime(const Lifetime &) [copy constructor]\n";
    }

    Lifetime(Lifetime&&) noexcept {
        std::cout <<"Lifetime(Lifetime &&) [move constructor]\n";
    }

    Lifetime& operator=(const Lifetime& other) noexcept {
        if (&other == this) {
             std::cout <<"self assignment! ";
        }
        std::cout << "operator=(const Lifetime &) [copy assignment operator]\n";
        return *this;
    }
    Lifetime& operator=(Lifetime&&) noexcept {
        std::cout <<"operator=(Lifetime &&) [move assignment operator]\n";
        return *this;
    }

    std::string key;
};
  
struct Compare_simple {
    bool operator()(const Lifetime& lhs, const Lifetime& rhs) const {
    return lhs.key < rhs.key;
    }
};

int main() {
    //0 - simple == OK
    //std::set<Lifetime, Compare_simple> set;
    //set.insert(Lifetime{"Bob"});//2 x ~Lifetime() [destructor] after std::move ??? WTF

    //ERROR: expected a type, got '<lambda closure object>main()::<lambda(const Lifetime&, const Lifetime&)>() 
    //std::set<Lifetime, [](const Lifetime& lhs, const Lifetime& rhs){return lhs.key < rhs.key;}> set_l;
    
    //1 => need type => decltype => temp lambda == OK
    //std::set<Lifetime, decltype ([](const Lifetime& lhs, const Lifetime& rhs){return lhs.key < rhs.key;})> set_l;
    //set_l.insert(Lifetime{"Dylan"});   

    //2 explicite lambla == OK
    //auto l = [](const Lifetime& lhs, const Lifetime& rhs){return lhs.key < rhs.key;};
    //std::set<Lifetime, decltype (l)> set_explicit_l;
    //set_explicit_l.insert(Lifetime{"Nick"});    

    //3 explicite lambla + allocator (third template parameter in set<>)== OK    
    //auto la = [](const Lifetime& lhs, const Lifetime& rhs){return lhs.key < rhs.key;};
    //std::set<Lifetime, decltype (la)> set_explicit_l_alloc {la};
    //template<class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>> class set;
    //decltype (la)== class Allocator 
    //set_explicit_l_alloc.insert(Lifetime{"Cave"});

    //4 using type deduction
    //auto lambda = [](const Lifetime& lhs, const Lifetime& rhs){return lhs.key < rhs.key;};
    //std::set myset{{Lifetime{"Cave"}}, lambda};//excess code
    
    //4.1 or directly in set
    std::set myset{{Lifetime{"Cave"}}, [](const Lifetime& lhs, const Lifetime& rhs){return lhs.key < rhs.key;}};//excess code
    myset.insert(Lifetime{"Freddy"});
}