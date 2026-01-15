// https://youtu.be/Lu1WsdQOi0E
// optional_implementation_over_union

// unions can be anonymous (unnammed)
// only one member is active (alive) at a time
// you can only access the currently active member
//    * any other access IS undefined behavior
// No member is the default member
// Unions can have constructors and destructors in C++11!
//    * but destructors are almost impossible to get correct!
// unions support regular member functions
// we need manual bookkeeping to know the active member
// there is a paper for compile-time querying active member
//    * https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2641r1.html
// use std::optional or std::variant if that's what you want!

#include <string>
#include <type_traits>

template <typename Contained>
class Optional {
    union Data {
        constexpr ~Data() requires std::is_trivially_destructible_v<Contained> = default;
        constexpr ~Data() {}

        Contained data;
    };

    Data data{};

    bool is_active = false;

   public:
    constexpr Optional() {}
    constexpr ~Optional() requires std::is_trivially_destructible_v<Contained> = default;
    constexpr ~Optional() {
        if (is_active) {
            std::destroy_at(&data.data);
        }
    }

    constexpr const Contained& get() { return data.data; }

    constexpr Optional& operator=(const Contained& new_obj) {
        if (is_active) {
            data.data = new_obj;
        } else {
            is_active = true;
            std::construct_at(&data.data, new_obj);
        }
        return *this;
    }
};

consteval auto use_optional() {
    Optional<std::string> obj;
    Optional<std::string> obj2;
    obj2 = "Hello world long string";
    return obj2.get().size();
}

int main() {
    static_assert(std::is_trivially_destructible_v<Optional<int>>);
    return static_cast<int>(use_optional());
}