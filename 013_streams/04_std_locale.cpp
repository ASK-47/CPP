#include <codecvt>
#include <iostream>
#include <locale>

std::ostream& operator<<(std::ostream& os, const std::locale& loc) {
    if (loc.name().length() <= 80)
        os << loc.name();
    else
        for (const auto c : loc.name()) os << c << (c == ';' ? "\n  " : "");

    return os << '\n';
}

int main() {
    std::locale l1;
    std::cout << "Name of a copy of the classic \"C\" locale: " << l1;

    std::locale l2("en_US.UTF-8");
    std::cout << "Name of unicode locale: " << l2;

    std::locale l3(l1, new std::codecvt_utf8<wchar_t>);
    std::cout << "Name of \"C\" locale except for codecvt: " << l3;

    std::locale l4(l1, l2, std::locale::ctype);
    std::cout << "Name of \"C\" locale except for ctype, which is unicode:\n  "
              << l4;
}