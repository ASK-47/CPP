// https://en.cppreference.com/w/cpp/io/manip/flush
//  std::flush
#include <chrono>
#include <iostream>

template <typename Diff>
void log_progress(Diff d) {
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(d) << " ... " << std::flush;
}

int main() {
    int sink = 0;

    auto t1 = std::chrono::high_resolution_clock::now();

    for (int j = 0; j < 5; ++j) {//Without std::flush, the output would be the same, but may not appear in real time.
        for (int n = 0; n < 100000; ++n)
            for (int m = 0; m < 200000; ++m) sink += m * n;  // do some work
        auto now = std::chrono::high_resolution_clock::now();
        log_progress(now - t1);
    }
    std::cout << '\n';
}