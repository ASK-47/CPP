//https://youtu.be/iMzEUdacznQ


#include <iostream>
#include <functional>

// type erasure: any mechanism that removes type information at runtime

struct Base {
    Base() = default;
    virtual ~Base() = default;
    // prevent slicing and other unexpected behaviors
   protected:
    // default or delete, protected, private or public,
    // it's up to what would make your code more correct
    Base(const Base&) = default;
    Base(Base&&) = default;
    Base& operator=(const Base&) = default;
    Base& operator=(Base&&) = default;
};

struct Derived : Base {};
struct Derived2 : Base {};

void use_type(const Base& b) {
    // inside here, the true type has been "erased"

    // but "aha," you say! I can simply dynamic_cast it!
    auto* d1 = dynamic_cast<const Derived*>(&b);

    if (d1 != nullptr) {
        // it's a d1!
    }
}

// "oh really?" Says I.
void break_your_assumptions() {
    struct MyDerived : Base {};

    // there is no literally *NO* way for
    // use_type to know the underlying type. That information
    // is simply not available.
    use_type(MyDerived{});
}

// This is a kind of 'normal' runtime polymorphism view of type erasure

// The more classical C++ example is something like
// std::function

void use_function(const std::function<int(int, int)>&) {}

// we can call use_function with *anything* that's callable

// a lambda, a free fuction, or another function
// object that has the same signature
// (see Ep 333 for more info on how this is implemented)

int add(int lhs, int rhs) { return lhs + rhs; }

void use_use_function() {
    struct S {
        int operator()(int lhs, int rhs) const { return lhs + rhs + constant; }

        int constant = 42;
    };

    use_function(add);
    use_function([](int lhs, int rhs) { return lhs * rhs; });

    S s{43};
    use_function(std::bind_front(&S::operator(), &s));
}

// another more modern technique is the notion of a "view"
class animal_view {
   public:
    template <typename Speakable>
    explicit animal_view(const Speakable& speakable)
        : object{&speakable},
          speak_impl{
              // create a lambda that knows how to unpack the stored object
              [](const void* obj) {
                  return static_cast<const Speakable*>(obj)->speak();
              }} {}

    void speak() const { speak_impl(object); }

   private:
    // void * to object of unknown type
    const void* object;

    // function pointer that knows how to use unknown type
    void (*speak_impl)(const void*);
};

void do_animal_things(animal_view animal) { animal.speak(); }

int main() {
    struct Cow {
        void speak() const { std::cout<<"Mooo\n"; }
    };

    struct Sheep {
        void speak() const { std::cout<<"Baaa\n"; }
    };

    // no polymorpism, no dynamic allocations, but still
    // a function indirection. From a performance perspective
    // we have not gained anything over a virtual function
    // call.

    // we have increased risk, some. We might end up with a dangling
    // reference.
    do_animal_things(animal_view{Cow{}});
    do_animal_things(animal_view{Sheep{}});
}

// in all cases the result is the same:
//
// 1) we are able to work with unknown user provided types
// 2) we have a compilation firewall that prevents having
//    to recompile the entire library to work with a new
//    type.

// We can accomplish 1) with templates (type inference), but not 2).
