// https://en.cppreference.com/w/cpp/memory/enable_shared_from_this.html
// enable_shared_from_this
//-std=c++23

#include <functional>
#include <iostream>
#include <memory>

class Good : public std::enable_shared_from_this<Good> {
   public:
    std::shared_ptr<Good> getptr() { return shared_from_this(); }
};

class Best : public std::enable_shared_from_this<Best> {
    struct Private {
        explicit Private() = default;
    };

   public: // Constructor is only usable by this class
    Best(Private) {}

    // Everyone else has to use this factory function
    // Hence all Best objects will be contained in shared_ptr
    static std::shared_ptr<Best> create() {
        return std::make_shared<Best>(Private());
    }

    std::shared_ptr<Best> getptr() { return shared_from_this(); }
};

struct Bad {
    std::shared_ptr<Bad> getptr() { return std::shared_ptr<Bad>(this); }
    ~Bad() { std::cout << "Bad::~Bad() called\n"; }
};

void testGood() {//good1.use_count() = 2 =>OK
    // Good: the two shared_ptr's share the same object
    std::shared_ptr<Good> good0 = std::make_shared<Good>();
    std::shared_ptr<Good> good1 = good0->getptr();//shared_from_this()
    std::cout << "good1.use_count() = " << good1.use_count() << '\n';
}

void misuseGood() {//bad_weak_ptr    
    // Bad: shared_from_this is called without having std::shared_ptr owning the caller
    try {
        Good not_so_good;
        std::shared_ptr<Good> gp1 = not_so_good.getptr(); //weak::shared_from_this(), but no first shared_ptr has't been was created!!!
    } catch (std::bad_weak_ptr& e) {
        // undefined behavior (until C++17) and std::bad_weak_ptr thrown (since C++17)
        std::cout << e.what() << '\n';
    }
}

void testBest() {//best1.use_count() = 2
    // Best: Same but cannot stack-allocate it:
    std::shared_ptr<Best> best0 = Best::create();
    std::shared_ptr<Best> best1 = best0->getptr();
    std::cout << "best1.use_count() = " << best1.use_count() << '\n';
    // Best stackBest; // <- Will not compile because Best::Best() is private!!!
}

void testBad() {
    // Bad, each shared_ptr thinks it is the only owner of the object
    std::shared_ptr<Bad> bad0 = std::make_shared<Bad>();//weak
    std::shared_ptr<Bad> bad1 = bad0->getptr();//another weak
    std::cout << "bad1.use_count() = " << bad1.use_count() << '\n';
}  // UB: double-delete of Bad

int main() {
    testGood();//good1.use_count() = 2
    misuseGood(); //bad_weak_ptr  

    testBest(); //best1.use_count() = 2

    //testBad();
    //double free or corruption (out)
    //Program terminated with signal: SIGSEGV
}