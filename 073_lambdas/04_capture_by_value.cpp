// hhttps://www.geeksforgeeks.org/cpp/lambda-capture-of-this-in-cpp-17/
// C++11:: capture 'this' == ref/ptr => dangling ref/ptr
// C++17:: capture *this' == capture by value == copy this

#include <iostream>

class Counter {
   public:
    Counter() : count(0) {}
    
    void Increment() {
        auto incrementLambda =
            [*this]() mutable {  // Define a lambda that captures *this by value                
                count++; // Access the count member variable and increment it
            };
        incrementLambda();  // Call the lambda to perform the increment
    }

    int GetCount() const { return count; }

   private:
    int count;
};

int main() {    
    Counter counter;    
    counter.Increment();
    counter.Increment();

    //capture *this by value using [*this].
    //lambda gets its own copy of *this and can modify the count without affecting the original object
    std::cout << "Count: " << counter.GetCount() << '\n'; // 0   
}