//folding_over_comma

#include <iostream>

//In lack of folding expressions
template <class... T>
void print_all(std::ostream& os, T const&... t) {
    using expander = int[];
    (void)expander{0, (void(os << t), 0)...};
}

//Over fold expressiom + operator ,
template <class... T>
void print_all_fold (std::ostream& os, T const&... t) {
    ((os << t << ' '), ...); //os << 1, os << 2, os << 3, os << 4, os << 5) + the comma operator
}

int main () {
    print_all_fold(std::cout, 1, 2, 3, 4, 5);

}