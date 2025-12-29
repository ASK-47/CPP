//https://youtu.be/JxYD8_OHQg8?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//lambda_usability_changes_c20

//-std=c++23 -Wpedantic -Wall -Wextra -Wconversion -O3 -Werror

int main() {
    //C++20
    [[maybe_unused]] auto l1 = []{};//Default constuctable stateless-lambda 
    [[maybe_unused]] auto l2 = []{};//Default constuctable stateless-lambda 
    [[maybe_unused]] auto l3 = []{return 5;};//Default constuctable stateless-lambda 
    
    [[maybe_unused]] auto m=l3;//copy - OK for C++17
    l3=m;//OK for C++20 => Default assignable lambda 
    //C++17 => ERROR:  use of deleted function 'main()::<lambda()>& main()::<lambda()>::operator=(const main()::<lambda()>&)'

    [[maybe_unused]] decltype(l3) n;//new lambls of l3-type - OK for C++20
    //C++17 => ERROR:a lambda closure type has a deleted default constructor

    [[maybe_unused]] decltype([]{}) l4;//OK for C++20 => Default assignable lambda 

}