//https://youtu.be/QhY7Fx-YsGs?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//lambdas_in_fold_expressions

#include <cstdio>

template<typename...T>
auto sum (T...t) {
    return (t+...);
}

template<typename...T>
auto sum_with_lambda (T...t) {
    return ([t](){return 2*t;}() + ...);// () to invoke the lambda
}

int main() {
    printf("sum = %d\n", sum(1, 2, 3, 4, 5, 6, 7, 8, 9));
    printf("sum_with_lambda = %d\n", sum_with_lambda(1, 2, 3, 4, 5, 6, 7, 8, 9));
}