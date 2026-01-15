//https://t.me/cpp_ready/1833
//std_launder

#include <iostream>

struct S {
    int m_x;
    S(int x) : m_x(x) {}
};

int main() {
    alignas(S) unsigned char storage [sizeof(S)];
    
    S* p=new(storage) S(42);
    std::cout << p->m_x <<'\n';
    p->~S();//destroy S(42) under p

    new(storage) S(100500);// new S(100500) object at storage
    
    //S* q=std::launder(p);//UB!!! WRONG to reload p as
    S* q=std::launder(reinterpret_cast<S*>(storage));//Need storage to reload
    std::cout << q->m_x <<'\n';

    //Explanation of fix:
    //storage is a pointer to the raw memory.
    //After placement new, reinterpret_cast<S*>(storage) gives you a pointer to the new object.
    //But the C++ standard says: if you access an object through a pointer that was obtained before the object was created, that’s UB — even if the pointer points to the same address.
    //std::launder tells the compiler: “I know this pointer points to storage where a new object now lives — treat it as valid.”
    //So you must use std::launder on a pointer to the storage, not the old object.


}