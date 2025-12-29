//https://youtu.be/9L9uSHrJA08?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//lambdas_with_destructors

#include <iostream>
#include <cstdio>



int main() {
    //1 lamblda captured by lambda    
    auto l1= [i=[](){return 42;}](){
        return i();
    };
    std::cout<< l1() <<'\n';

    //2 struct captured by lambda captured by invoked lambda  
    auto l2= [i=[]() {
        struct S {
            int val=10500;
            S() {puts("S is created");};
            S(const S&) {puts("S is copied");};
            ~S() {puts("S is destroyed");};
        };
        return S{};
    }()]//() - to invoke i() => return S{}
    (){return i;};//to return copy of returned S{}

    std::cout << l2().val <<'\n';

    auto l3=l2;
    
}