// https://youtu.be/n8pn1swPrOg
// Type erasure for std::any implementation

#include <iostream>

class any {
   public:
    template <typename U>
    // any(const U& value) : storage(new U(value)){}
    explicit any(const U& value) : storage(new Derived<U>(value)) {}
    // D-tor
    ~any() {
        // this->~U();????
        // storage-> destroy();//=> destroy Base::~T()=>Derived<T>::~T()
        delete storage;  //=>delete Derived<T> =>delete value
    }
    // copy C-tor
    any(const any& a) : storage(a.storage->clone()) {}
    // operator=any
    any& operator=(const any& a) {
        if (storage == a.storage) return *this;
        delete storage;
        storage = a.storage->clone();
        return *this;
    }
    // operator=a(value)
    template <typename U>
    any& operator=(const U& value) {
        delete storage;
        storage = new Derived<U>(value);
        return *this;
    }

   private:
    struct Base {
        // virtual void destroy();
        virtual Base* clone();
        virtual ~Base() {}
    };
    template <typename T>
    struct Derived : Base {
        T value;
        Derived(const T& value_) : value(value_) {}
        // void destroy() {~T();};
        Base* clone() override { return new Derived<T>(value); };
    };

    // void* storage;//storage=new T(value) //implicit static_cast<*void> is
    // included
    Base* storage;
};

int main() {
    any a(42);
    any b = a;
    any c{2.0f};
    c = a;
    c = 'c';
}