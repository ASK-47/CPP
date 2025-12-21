//https://youtu.be/XhxV1NP5RGs?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//lambdas_for_resource_managment

#include <memory>

int main() {   
    
    //auto deleter = [](FILE*f){fclose(f);};
    //auto file = std::unique_ptr<FILE, decltype(deleter)> (fopen("lambdas_file.txt", "w"), deleter);
    //or
    //auto file = std::unique_ptr<FILE, decltype(deleter)> (fopen("lambdas_file.txt", "w"));//Since C++20 (lambda are default constructible)
    
    //or
    auto file = std::unique_ptr<FILE, decltype([](FILE*f){fclose(f);})> (fopen("lambdas_file.txt", "w"));

}