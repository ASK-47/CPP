//https://youtu.be/qmd_yxSOsAE
//put_lambda_in_a_container

#include <iostream>
#include <vector>
#include <functional>

//lambda_type 5.1
auto make_lambda(int value) {
    return [value] (int k) {return value+k;};
}

using lambda_vector=std::vector<decltype(make_lambda(10500))>;//Problem relies on a type of the lambda => ODR problem
auto make_lambda_vector() -> lambda_vector {
    lambda_vector vec;
    vec.push_back(make_lambda(1));
    vec.push_back(make_lambda(2));
    return vec;
}

//lambda_type 5.2
struct my_lambda {
    int value;
    int operator() (int k) {
        return value+k;
    }    
};

auto make_lambda2(int value) ->my_lambda {
    return my_lambda(value);
}


using lambda_vector2=std::vector<decltype(make_lambda2(42))>;
auto make_lambda_vector2() -> lambda_vector2 {
    lambda_vector2 vec;
    vec.push_back(make_lambda2(45));
    vec.push_back(make_lambda2(10500));
    return vec;
}


int main() {
    auto l= [i=42](auto j) mutable {return ++i + j;};
    
    //1 decltype(l)
    std::vector<decltype(l)> data1;
    data1.push_back(l);//OK for mutable lambda
    std::cout << l(100500) << '\n';

    //2 std::function - to much code in assembler
    std::vector<std::function<int(int)>> data2;
    data2.push_back(l);
    data2.push_back([](auto k){return k*k;});
    
    //3 function pointer for non captured lambda-objects
    auto l3= [](auto j)  {return 42+j;};
    std::vector<int(*)(int)> data3;
    data3.push_back(l3);

    //4 decltype(l) again
    //std::vector<decltype(l)> data4;
    //auto l4= [](int j)  {return 10500+j;};
    //data4.push_back(l4);//Error - no known conversion for argument 1 from one lambda....to another
    
    //5 => trick == make_lambda function
    std::vector<decltype(make_lambda(41090))> data5;
    data5.push_back(make_lambda(10500));
    data5.push_back(make_lambda(42));

    //5.1 using helper == make_lambda_vector
    auto data51 = make_lambda_vector();

    //5.2 using helper == make_lambda_vector
    auto data52 = make_lambda_vector2();


}
