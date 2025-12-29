//https://youtu.be/i2HyDHAVBsk?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//lambda_typeid

#include <cstdio>
#include <typeinfo>

int main() {
    auto l = [](){};
    puts(typeid(l).name());
    //Z4mainEUlvE_
    //Z - Indicates a global symbol (not nested in an external namespace)
    //4main - main lenght==4
    //E Marks the end of the qualified (nested) name - main
    //U - Starts a nested name or substituted type, often for anonymous items like lambdas, enums, or local classes
    //lv - local variable" or lambda context
    //E_ - End of the nested element
    //_        
}