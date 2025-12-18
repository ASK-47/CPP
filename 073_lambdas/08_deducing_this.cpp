//https://youtu.be/f0heIju3udc
//deducing_this

#include <iostream>

int main() {
    auto lambda = [](this auto & self){ //deducing_this since C++23 => now lambda know about Derived (looks like CRTP)
        self.update_value();
        return self.value;
        //return 42;
    };

    using Base = decltype(lambda);

    struct Derived : Base {//now Derived has lambda
        void update_value (){ //how inject update_values into lambda
            value+=100500;
        };
        int value=0;

    };

    [[maybe_unused]] Derived d;
    //d.update_values();
    //return d(); // 42 from lambda 
    printf ("update_value=%d\n", d());//100500
    printf ("update_value=%d\n", d());//100500
}
