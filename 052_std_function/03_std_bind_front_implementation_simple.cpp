// https://youtu.be/9laCL5GixNk
#include <functional>

template <auto Func, auto... Vals>
consteval auto bind_front() {
    return []<typename... Param>(Param&&... param) static -> decltype(auto) {
        return Func(Vals..., std::forward<Param>(param)...);
    };
}

int add(int x, int y) { return x + y; }

int main() {
    auto bound = bind_front<add, 2>();
    static_assert(sizeof(bound) == 1);
    return bound(10);
}