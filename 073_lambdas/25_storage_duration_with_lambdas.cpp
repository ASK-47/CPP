//https://youtu.be/WUvF4W98vq4?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//storage_duration_with_lambdas
#include <iostream>
#include <thread>
#include <future>

int main() {
    auto l=[]() mutable {        
        //static auto val=0;//common for all lambdas => but not thread safe!        
        
        thread_local  auto val=0;//common for thread! == static for one thread!!!
        //thread_local ensures each thread has its own separate instance of val.
        //The variable persists across calls within the same thread but is isolated between threads.

        return ++val;
    };
    
    auto l2=l;

    
    auto f=std::async(std::launch::async,l);    
    //std::async(std::launch::async, l) executes l in a new thread, incrementing the shared static val 0 → 1
    
    //f.get() waits for completion, ensuring the increment happens before main thread calls proceed
    //if commented << 1 2 3 4
    //if not commented << 2 3 4 5
    f.get();
    //f.get() waits for completion (result discarded).
    //TO FIX: static auto => thread_local auto =>  << 1 2 3 4
    
    std::cout << l2() <<'\n';
    std::cout << l() <<'\n';
    std::cout << l2() <<'\n';    
    std::cout << l() <<'\n';    
}