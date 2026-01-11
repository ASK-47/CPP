//https://youtu.be/f0heIju3udc?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//interface_injection_into_lambda_simple

int main() {//using deducing this C++23
    auto lambda =[](this auto& self) {
        self.update_val();
        return self.val;
    };

    using Base=decltype(lambda);
    
    struct Derived : Base {
        void update_val () {
            val+=42;
        }
        int val=100500;
    };

    Derived d;
    return d();//call operetor() from lambda => call  self.update_val() +  return self.val
}
