//https://t.me/grokaemcpp/720
//std::invoke

#include <iostream>
#include <functional>

//std::invoke. Это функция буквально создана, чтобы вызывать все, что только можно вызвать. Она конечно же написана на вариабельных шаблонах, чтобы вы могли передать туда все, что душе угодно


//1 problem process_and_call implementation
template <typename Callback, typename... Args>
void process_and_call_bad(Callback&& callback, Args&&... args) {
  // some processing
  std::forward<Callback>(callback)(std::forward<Args>(args)...);
}

//1 correct  process_and_call implementation
template <typename Callback, typename... Args>
void process_and_call_good(Callback&& callback, Args&&... args) {
  // some processing
  std::invoke(std::forward<Callback>(callback), std::forward<Args>(args)...);
}



class Data {
public:
    void memberFunction(int value) {
        std::cout << "Data::memberFunction called with value: " << value << "\n";
    }
};

void f(int x) {
    std::cout << "f called with value: " << x << "\n";
}

int main() {
    //Problem with pointer to class method
    process_and_call_bad(f, 42); //OK
    process_and_call_bad(&f, 42); //OK    
    Data data;    
    auto methodPtr = &Data::memberFunction;// Создаем указатель на метод класса
    //process_and_call_bad(*methodPtr, 42); //Error for *!!!
    (data.*methodPtr)(42);// Вызываем метод через указатель на объекте - OK

    process_and_call_bad(&Data::memberFunction, Data{}, 42);//Error
    process_and_call_good(&Data::memberFunction, Data{}, 42);//OK  
    
}