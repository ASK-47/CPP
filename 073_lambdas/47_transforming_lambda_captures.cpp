//https://youtu.be/t6hFPKiOS-Q?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//transforming_lambda_captures

#include <iostream>

template<typename...String>
void string_func (const String&...s) {
    auto l=[...str_like=std::string_view{s}](){//capture parameter is transformed ti a string 
        ((std::cout << str_like.size() << ' ' << str_like << '\n'),...);
    };
    l();
};

int main() {
    string_func ("AAAAA", std::string("BBBB"), std::string_view("CCC"));    
}
