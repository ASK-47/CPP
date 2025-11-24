#include <iostream>
#include <vector>

// 1 for enum with only consecutive values:
enum E { Begin, E1 = Begin, E2, En, End };

// 2 with enum class, operator ++ has to be implemented:
enum class EE { Begin, E1 = Begin, E2, En, End };
EE& operator++(EE& e) {
    if (e == EE::End) {
        throw std::out_of_range("for EE& operator ++ (EE&)");
    }
    e = EE(static_cast<std::underlying_type<EE>::type>(e) + 1);
    return e;
}

// 3 over std::vector:
enum EEE { EEE1 = 4, EEE2 = 8, EEEn };

std::vector<EEE> build_all_E() {
    const EEE all[] = {EEE1, EEE2, EEEn};
    return std::vector<EEE>(all, all + sizeof(all) / sizeof(EEE));
}

int main() {
    // 1 for enum with only consecutive values:
    for (int e = E::Begin; e != E::End; ++e) {  // e==int
        std::cout << e << ' ';
    }

    // 2 with enum class, operator ++ has to be implemented:
    for (EE e = EE::Begin; e != EE::End; ++e) {  // e==int
        std::cout << static_cast<int>(e) << ' ';
    }

    // 3 over std::vector
    std::vector<EEE> all_E = build_all_E();
    for (std::vector<EEE>::const_iterator it = all_E.begin(); it != all_E.end();
         ++it) {
        EEE e = *it;
        std::cout << e << ' ';
    }
}