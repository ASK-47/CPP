// https://t.me/cplusplus_tg/130
// DEBUG_macros

// #define NDEBUG// if not defined NDEBUG => debag only
#include <iostream>
#include <map>

#ifdef NDEBUG
#define DEBUG(var)  // for debug only
#else
#define DEBUG(var)                                \
    {                                             \
        std::cout << #var << ": " << var << '\n'; \
    }
#endif

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const ::std::map<T1, T2>& m) {
    out << "{ ";
    for (const auto& [key, value] : m) out << key << "->" << value << ", ";
    out << "}";
    return out;
}

int main() {
    int x{10500};
    DEBUG(x);

    std::map<std::string, int> m;
    m["AAA"] = 10;
    m["BBB"] = 20;
    m["CCC"] = 30;
    m["DDD"] = 40;
    m["EEE"] = 50;
    std::cout << m;
}
