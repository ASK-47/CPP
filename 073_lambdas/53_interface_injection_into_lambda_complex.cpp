// https://youtu.be/f0heIju3udc?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
// interface_injection_into_lambda_complex

#include <iostream>

template <typename... Base>
struct Overloaded : Base... {
    using Base::operator()...;
    void update_val() { val += 42; }
    int val = 100500;
};

template <typename... Base>
Overloaded(Base&&...) -> Overloaded<Base...>;

int main() {  // using deducing this C++23
    Overloaded d {
        [](this auto& self, int i) {
            self.update_val();
            std::cout << "i=" << i << " val=" << self.val <<'\n';
            return self.val;
        },
        [](this auto& self, double d) {
            self.update_val();
            std::cout << "d=" << d << " val=" << self.val <<'\n';
            return self.val;
        }        
    };
    d(4);
    d(3.14);
}
