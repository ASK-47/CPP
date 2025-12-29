// https://youtu.be/9mWWNYRHAIQ?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//optimal_way_to_return_from_function
#include <string>

/*std::string get_value_1(const bool b) {//37 LINES
    std::string ret{}; //inii
    if (b) {
        ret="Hello";//assign
        return ret;
    } else {
        ret="World";//assign
    }
    return ret;//RVO
}*/

/*std::string get_value_ternary_bad(const bool b) {//115 LINES    
    return b ? "Hello": "Worlds";    
}*/

/*std::string get_value_good(const bool b) {//23 LINES    
    if (b) return "Hello";     
    return "Worlds";     
}*/

/*std::string get_value_ternary_good(const bool b) {//23 LINES    
    return b ? std::string("Hello"): std::string("Worlds");    
}*/

/*const char* get_value_very_good1(const bool b) {//13 LINES but neef to convert into string    
    if (b) return "Hello";     
    return "Worlds";     
}
//+string conversion
std::string get_string(const bool b) {//121 LINES!!!
    return get_value_very_good1(b);     
}*/

/*std::string_view get_value_very_good2(const bool b) {//19 LINES but neef to convert into string    
    if (b) return "Hello";     
    return "Worlds";     
}
//+string conversion
std::string get_string(const bool b) {//56 LINES!!!
    return std::string(get_value_very_good2(b));     
}*/

std::string get_value_best(const bool b) {//20 LINES
    if (b) return std::string("Hello");
    return std::string("World");
}
int main() {}