//https://t.me/grokaemcpp/729
//no_captured_lampda
#include <iostream>

int apply_function(int (*func)(int), int value) {
    return func(value); // Вызываем переданную функцию
}


int main() {
    [[maybe_unused]] auto fun = [](int i) { return i*2;};

//=====C++Insights======

  /*class __lambda_7_33 {
    public: 
    inline  int operator()(int i) const {// оператор вызова operator()
      return i * 2;
    }    
    using retType_7_33 = int (*)(int);
    inline constexpr operator retType_7_33 () const noexcept {// оператор приведения к указателю на функцию
      return __invoke;
    };    

    private:     
    static inline int __invoke(int i) {//статический метод на лету конструирует объект и вызывает у него operator()
      return __lambda_7_33{}.operator()(i);
    }

    public:
    // __lambda_7_33() = default;    
  };  
    
    [[maybe_unused]] __lambda_7_33 fun = __lambda_7_33{};
*/
///=====================
    fun(42);//lampda call 

    apply_function(fun, 42);//callback lambda to apply_function as function pointer
    //Вызывать лямбду через указатель на функцию - это лишить себя основной оптимизации компилятора - инлайнинга.
    //Если передавать лямбду, как полноценный тип замыкания, то компилятор будет знать, как встроить код его operator() внутрь callee
    //потому что все типы определены на этапе компиляции. А по указателю на функцию можно передать все, что угодно.
    //В простых случаях, как в apply_function, может и все хорошо будет. Но в более сложных - вы лишитесь оптимизации.
}