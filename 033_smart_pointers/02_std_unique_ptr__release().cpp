//https://t.me/cplusplus_tg/3052
//std::unique_ptr::release()

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr= std::make_unique<int>(42);
    
    [[maybe_unused]]int* row_ptr=ptr.release();
    if(!ptr) 
        std::cout << "unique_ptr == nullprt" << '\n';

    std::cout << "after release row_ptr == " << *row_ptr<<'\n';

    delete row_ptr;
}