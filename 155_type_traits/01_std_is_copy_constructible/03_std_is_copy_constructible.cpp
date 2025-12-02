#include <string>
#include <type_traits>

struct S1 {
    std::string str;  // member has a non-trivial copy constructor
};
static_assert(std::is_copy_constructible_v<S1>);
static_assert(!std::is_trivially_copy_constructible_v<S1>);

struct S2 {
    int n;
    S2(const S2&) = default;  // trivial and non-throwing
};
static_assert(std::is_trivially_copy_constructible_v<S2>);
static_assert(std::is_nothrow_copy_constructible_v<S2>);

struct S3 {
    S3(const S3&) = delete;  // explicitly deleted
};
static_assert(!std::is_copy_constructible_v<S3>);

struct S4 {
    S4(S4&) {};  // cannot bind const, hence not a copy-constructible
};
static_assert(!std::is_copy_constructible_v<S4>);

int main() {}