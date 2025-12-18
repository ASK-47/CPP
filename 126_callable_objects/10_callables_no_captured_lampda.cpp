// https://t.me/grokaemcpp/726
// callables_no_captured_lampda

#include <iostream>
#include <vector>

void print(const std::vector<int>& vec) {
    for (int v : vec) printf("%d ", v);
    printf("\n");
}

int main() {
    std::vector<int> nums = {5, 3, 9, 1};
    print(nums);
    std::qsort(nums.data(), nums.size(), sizeof(int),
    [](const void* a, const void* b) -> int {
      return ( *(int*)a - *(int*)b);
    });
    print(nums);
}