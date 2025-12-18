//https://youtu.be/287_oG4CNMc
//lifetime_tool_basic

#include <cstdio>
#include <utility>

struct Lifetime {
    Lifetime() noexcept { puts("Lifetime() [default constructor]\n"); }
    ~Lifetime() noexcept { puts("~Lifetime() [destructor]\n"); }
    Lifetime(const Lifetime&) noexcept {
        puts("Lifetime(const Lifetime &) [copy constructor]\n");
    }
    Lifetime(Lifetime&&) noexcept {
        puts("Lifetime(Lifetime &&) [move constructor]\n");
    }

    Lifetime& operator=(const Lifetime& other) noexcept {
        if (&other == this) {
            puts("self assignment! ");
        }
        puts("operator=(const Lifetime &) [copy assignment operator]\n");
        return *this;
    }
    Lifetime& operator=(Lifetime&&) noexcept {
        puts("operator=(Lifetime &&) [move assignment operator]\n");
        return *this;
    }
};

Lifetime f1() {
    return Lifetime{};
}

Lifetime f2() {
    return f1();
}

Lifetime f3() {
    return f2();
}


int main() {
    /*puts("Before lambda construction\n");
    auto lambda = [lft = Lifetime{}]() {};

    puts("Before lambda call\n");
    lambda();
    puts("After lambda call\n");*/

    //1
    //Lifetime l1=f3();//only one object was created and destriyed!!!

    //2
    //[[maybe_unused]]auto l2=[](){return f3();};
    //l1();//only one object was created and destriyed!!!

    //3
    //[[maybe_unused]]auto l3=[](){Lifetime{};};//it'a OK???

    //4
    //auto lt=Lifetime{};
    //[[maybe_unused]]auto l4=[lt=std::move(lt)](){Lifetime{};};//it'a OK???
    //l4();

     //5
    //auto lt=Lifetime{};
    //[[maybe_unused]]auto l=[lt=std::move(lt)](){Lifetime{};};//it'a OK???
    //auto l5=l; //3 Dtors
    
}