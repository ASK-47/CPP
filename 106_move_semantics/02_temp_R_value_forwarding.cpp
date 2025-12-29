// https://youtu.be/VEqOOKU8RjQ?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
// temp_R_value_forwarding

#include <utility>
#include <cstdio>

template <typename First, typename Second>
struct Pair1 {
    First first;
    Second second; 
};

template <typename First, typename Second>
struct Pair2 {
    First first;
    Second second;

    template <typename First_, typename Second_>
    Pair2(First_&& f_, Second_&& s_)
        : first(std::forward<First_>(f_)), second(std::forward<Second_>(s_)) {}
};

struct Helper {
    Helper(int i) {std::printf("Helper(%d)\n", i);}
    Helper() {std::puts("Helper()");}
    ~Helper() {std::puts("~Helper()");}
    Helper(const Helper&) {std::puts("Helper(const Helper&)");}
    Helper(Helper&&) {std::puts("Helper(Helper&&)");}
    Helper& operator= (const Helper&) {
        std::puts("operator=(const Helper&)");
        return *this;
    }
    Helper& operator= (Helper&&) {
        std::puts("operator=(Helper&&)");
        return *this;
    }
};

int main() {
    //no perfect forwarding
    Pair1<Helper, Helper> pair_1 {Helper{1}, Helper{2}};
    std::puts("=========");
    //perfect forwarding
    Pair2<Helper, Helper> pair_2 {Helper{3}, Helper{4 }};//temp R-value forwarding into => Helper(Helper&&)
    std::puts("=========");

}