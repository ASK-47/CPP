//https://youtu.be/nhk8pF_SlTk
//fold_expressions_intro
#include <iostream>

//C++17
template<typename... T>
auto sum (T...t) {
    return (...+t);
}

//... is always in (...)
//... == (...) 
template<typename... T>
auto div1 (T...t) {
    return (t/...); // t/(t(/t/t))
}

template<typename... T>
auto div2 (T...t) { //(t/t)/t)/t)
    return (.../t);
}

template<typename... T>
auto div3 (T...t) { //(t/t)/t)/t)
    const int n=72;
    //Binary Left Fold - (value op ... op pack)
    return (n/.../t);// ((n/t)/t)...
    
    //Binary Right Fold (pack op ... op value)
    // t/(t/(t/n))

}

template<typename... T>
auto size_of (T...t) {    
    //sizeof...(t) counts the arguments in that pack    
    std::cout << sizeof...(t) <<'\n';
}

template<typename... T>
auto average (T...t) {    
    //sizeof...(t) counts the arguments in that pack    
    return (t+...)/sizeof...(t);
}


int main() {
    std::cout << sum (1, 2, 3, 4, 5, 6, 7, 8, 9 ) <<'\n';
    
    std::cout << div1 (55, 9, 6, 2) <<'\n';//27/(9/(6/2))=27(9/3)=54/3=9
    std::cout << div2 (24, 3, 4) <<'\n';//(24/3)/4=8/4=2
    std::cout << div2 (18.0, 3.0, 4) <<'\n';//(18/3)/2=6/4=1.5
    std::cout << div3 (4, 3, 2) <<'\n';//(72/4)/3)/2=18/3/2=6/2=3
    
    size_of (1, 2, 3, 4, 5, 6, 7, 8, 9 );//9 digits in pack

    std::cout << average (1, 2, 3, 4, 5, 6, 7, 8, 9 ) <<'\n';//45/9=5

}