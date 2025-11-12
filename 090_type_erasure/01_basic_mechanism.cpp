#include <iostream>

class Printable {
   public:
    template <typename T>
    Printable(T value) : pValue(new Value<T>(value)) {}
    ~Printable() { delete pValue; }
    void print(std::ostream& os) const { pValue->print(os); }

   private:
    Printable(Printable const&) /* in C++1x: =delete */;  // not implemented

    void operator=(
        Printable const&) /* in C++1x: =delete */;  // not implemented

    struct ValueBase {  // WHY do we need interface ??? <=> to inheritate
                        // Value<T> - with any type of T
        virtual ~ValueBase() = default;
        virtual void print(std::ostream&) const = 0;
    };

    template <typename T>
    struct Value : ValueBase {
        Value(T const& t) : v(t) {}
        virtual void print(std::ostream& os) const { os << v << '\n'; }
        T v;
    };
    ValueBase* pValue;
};

// At the definition of the concrete type, nothing needs to be known about
// Printable, it just needs to conform to an interface, as with templates:
struct Fuck_Type {
    int i;
};
std::ostream& operator<<(std::ostream& os, Fuck_Type const& mc) {
    return os << "Fuck Type {" << mc.i << "}";
}

void print_value(Printable const& p) {
    p.print(std::cout);
};  // can be used for any type of argument (see below const char*, float ...
    // etc.)

int main() {
    Printable p_const_char("42 100 500");
    print_value(p_const_char);

    Printable p_float(42.1005f);
    print_value(p_float);

    Fuck_Type ftp = {42};
    print_value(ftp);
}