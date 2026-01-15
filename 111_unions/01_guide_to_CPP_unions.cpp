//https://youtu.be/Lu1WsdQOi0E
//guide_to_CPP_unions

#include <iostream>

consteval auto use_union_1() {// consteval == radical constexpr
    union {
        int i;
        float f;
    };
    f=4.2f;
    i=42;
    return i;
}

consteval auto use_union_2() {
    union U {
        int i;
        double d;
        float f;
    };
    U u;
    u.f=3.14f;
    u.d=4.2;
    u.i=100500;
    //return sizeof(u);// 8 bytes == sizeof(double)
    
    //return u.f;//ERROR
    //return u.d;//ERROR
    return u.i;//OK
}

consteval auto use_union_3() {
    union U {
        constexpr U(){}
        constexpr ~U(){
            s.std::string::~string();//Dtor call - problem init value is not known => difficult to use Dtor corrective        
        }
        //std::string s{};//OK, but it is union usally no intialisation at construction        
        std::string s;//ERROR string is not init
    };        
    U u{};
    //std::construct_at(&u.s, "WTF");//construct the member of union
    //return u.s.size();//OK
    return 42;//ERROR <= string is not init
}

consteval auto use_union_4() {
    union U {
        int i;        
        float f;
        constexpr U() : i(42) {}
        constexpr U(float f) : f(f) {}        
    };
    U u{4.12f};     
    return u.f;
}

consteval auto use_union_5() {
    union U {
        int i;    
        float f;            
        constexpr U() : i(42) {}
        constexpr U(float f) : f(f) {}
        constexpr U& operator=(int val) {
            i=val;
            return *this;
        }
    };
    U u(33.14);
    return u.f;

    //u=32; //same as u(32);    
    //return u.i;
}


int main() {
    
    std::cout << use_union_1() << '\n';
    std::cout << use_union_2() << '\n';
    //std::cout << use_union_3() << '\n';
    std::cout << use_union_4() << '\n';
    std::cout << use_union_5() << '\n';

}
