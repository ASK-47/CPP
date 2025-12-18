// https://t.me/grokaemcpp/785
// dangling reference in lambda
#include <functional>
#include <iostream>

auto make_add_n(int n) {
    return [&](int x) {  // catch n by ref
        return x + n;    // n is deleted == n is dangling ref (clang:: n will
                       // become dangling reference!)
    };
};

struct Task {
    int id;

    //Problem
    /*std::function<void()> GetNotifier() {
      //1 
      //return [=]{//catch by ptr this (depricated) => UB!
      
      //2
      return [this] {//copy object by value = OK
        std::cout << "notify " << id << std::endl;
      };//this is destroyed => his is dangling ptr (ref)
    }*/

    //3 Solution for qick detection - методы с ref-квалификаторами
    std::function<void()> GetNotifier() && =
        delete;  // forbit call on temporaries

    std::function<void()> GetNotifier() & {
        return [this] { std::cout << "notify " << id << std::endl; };
    }
};

int main() {
    auto add5 = make_add_n(5);
    std::cout << add5(5) << std::endl;  // UB!

    //1 GetNotifier() catchs temp by ptr this, this is deleted when remp is deleted => notify1 is deleted object!
    //2 GetNotifier() catchs temp by copy of this == OK
    //3 Methos with ref-qualificators => to prevent dangling
    auto notify1 = Task{5}.GetNotifier();// ERROR - temp is R-value, GetNotifier() && for R- values is deleted
    notify1();
}