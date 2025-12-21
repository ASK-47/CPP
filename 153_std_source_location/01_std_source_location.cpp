//https://t.me/cplusplus_tg/3054
//std_source_location
#include <iostream>
#include <source_location>

void log_message (const std::string& message, std::source_location loc=std::source_location::current()) {
    std::cout   << "File: " << loc.file_name()
                << ", String: " << loc.line()
                << ", Function: " << loc.function_name()
                << " => " << message << '\n';
}

int main() {
    log_message("Error in code");

}