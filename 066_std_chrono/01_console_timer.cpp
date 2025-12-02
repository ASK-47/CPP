//https://t.me/cpp_ready/1680
//Консольный таймер обратного отсчёта

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

std::string format_time(int timer_time_seconds) {
    int min = timer_time_seconds / 60;
    int sec = timer_time_seconds % 60;

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << min << ':' << std::setw(2)
        << std::setfill('0') << sec << '\n';
    return oss.str();
}

int main() {
    std::cout << "Enter timer time, sec" << '\n';
    int timer_time_seconds{};
    if (!(std::cin >> timer_time_seconds) or timer_time_seconds <= 0) {
        std::cout << "Failure! Please, enty the inegral mumber!" << '\n';
        return 0;
    }

    for (int rem = timer_time_seconds; rem>=0; --rem) {        
		//std::cout << "Remain " << format_time(rem) << std::endl; //std::flush + '\n'		
		std::cout << "Remain " << format_time(rem) << std::flush;		
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}