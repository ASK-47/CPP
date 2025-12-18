//https://t.me/grokaemcpp/874
//идиома IILE(Immediately Invoked Lambda Expression).

#include <iostream>
#include <functional>

 int computeFunc (int x) {
    return x*x;
 }

int main() {
    bool bFirstContidion=1;
    bool bSecondCondition=1;
    int inputParam =42;

    //Хочется и const сделать, и в отдельную функцию не выносить. Кажется, что на двух стульях не усидишь, но благодаря лямбдам...
    //1 using lambda
    const int myVariable = [&] {
        if (bFirstContidion)
            return bSecondCondition ? computeFunc(inputParam) : 0;
        else
            return inputParam * 2;
    }();  // () == call!?!?    
    std::cout << myVariable << '\n';

    //2 using std::invoke

    const int my_Variable=std::invoke([&] {
        if (bFirstContidion)
            return bSecondCondition ? computeFunc(inputParam) : 0;
        else
            return inputParam * 2;
    });

    std::cout << my_Variable << '\n';

}