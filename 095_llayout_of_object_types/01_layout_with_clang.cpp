// https://youtu.be/Mb8Bo-pmIJs?list=PLEn0tSs_m1wH2cB_a5LsET83W6QiDs29l&t=4518
// x86-64 clang -O2 -Xclang -fdump-record-layouts
#include <cstddef>
#include <cstdint>

struct s {
    char a;
    char b;
    uint32_t u;
    char c;
};

size_t x = sizeof(s);
