//https://youtu.be/f0heIju3udc
//deducing_this_overloading_pattern

#include <cstdio>

template<typename ...Base>
struct overload:Base... {
    using Base::operator()...;
    void update_value (){ //how inject update_values into lambda
        value+=100500;
    }    
     int value=0;
};

template<typename ...Base>
overload (Base&&...) -> overload<Base...>;

int main() {
    overload d {[](this auto & self, int i){ //deducing_this since C++23 => now lambda know about Derived (looks like CRTP)
        printf ("i=%f\t", i);
        printf ("update_value=%d\n", self.value);
        return self.value;        
    },
                [](this auto & self, double d){ //deducing_this since C++23 => now lambda know about Derived (looks like CRTP)
        printf ("i=%d\t", d);
        printf ("update_value=%d\n", self.value);
        return self.value;      
    }
    };    
    
    d(100500);
    d(3.14);        
}
