//https://youtu.be/kmza9U_niq4?list=PLs3KjaCtOwSY_Awyliwm-fRjEOa-SRbs-
//constexpr_lambda_support
#include <cstdint>
#include <array>
#include <algorithm>

struct Color {
    uint8_t num;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    double luma = 0.2126 * r + 0.7152 * g + 0.0722 * b;
};
  
template<typename Colors>//constexpr for CT  
constexpr auto nearest_color(const Colors &colors, const uint8_t r, const uint8_t g, const uint8_t b) {
    return *std::min_element(begin(colors), end(colors),        
        [r,g,b](const auto &lhs, const auto &rhs) {
            const auto square = [](const auto t) { return t * t; };
            return (square(lhs.r - r) + square(lhs.g - g) + square(lhs.b - b))
            < (square(rhs.r - r) + square(rhs.g - g) + square(rhs.b - b));
        }
    );
}

template<size_t N>
constexpr auto sort_by_luma(const std::array<Color, N> &colors) {
    // get copy of incoming data
    auto retval = colors;

    // Use std::get to get a non-const * to retval data
    //Pointer usage (&std::get<0>(retval)) is a workaround for array access in constexpr contexts;
    //it's valid in modern compilers.
    const auto array_head = &std::get<0>(retval);
    const auto end        = array_head + colors.size();

    // Loop over each position, finding the appropriate element,
    // and swapping it into place
    for (size_t i = 0; i < colors.size(); ++i) {
        const auto begin = array_head + i;
        // Treat pointers as iterators, perfectly valid
        auto minelem = std::min_element(begin, end, 
            [](const auto &lhs, const auto &rhs) {
                return lhs.luma < rhs.luma;
            }
        );      
        // swap in the newly found minimum element
        //Manual swaps instead of std::swap or std::sort to keep it simple and constexpr-friendly.
        const auto tmp = *minelem;
        *minelem = *begin;
        *begin = tmp;
    }
    return retval;
}

int main() {
    constexpr std::array<Color, 16> colors {{
        Color{0,  0x00, 0x00, 0x00},
        Color{1,  0xFF, 0xFF, 0xFF},
        Color{2,  0x88, 0x39, 0x32},
        Color{3,  0x67, 0xB6, 0xBD},
        Color{4,  0x8B, 0x3F, 0x96},
        Color{5,  0x55, 0xA0, 0x49},
        Color{6,  0x40, 0x31, 0x8D},
        Color{7,  0xBF, 0xCE, 0x72},
        Color{8,  0x8B, 0x54, 0x29},
        Color{9,  0x57, 0x42, 0x00},
        Color{10, 0xB8, 0x69, 0x62},
        Color{11, 0x50, 0x50, 0x50},
        Color{12, 0x78, 0x78, 0x78},
        Color{13, 0x94, 0xE0, 0x89},
        Color{14, 0x78, 0x69, 0xC4},
        Color{15, 0x9F, 0x9F, 0x9F}
    }
  };
    //For gray (128,128,128), the closest is color #12 (RGB: 120,120,120, luma ~120).
    // Verification: Other colors (e.g., #11: 80,80,80) have larger distance (~3 times farther).
    static_assert(12 == nearest_color(colors, 128, 128, 128).num);
  
    //For black (0,0,0), closest is color #0 (black). Obvious, as distances increase for all others.
    static_assert(0  == nearest_color(colors, 0, 0, 0).num);

    constexpr auto sorted_colors = sort_by_luma(colors);

    static_assert(sorted_colors[0].num == 0);// First (darkest) is black.
    static_assert(sorted_colors[7].num == 14);//8th (0-indexed) is color #14.
    static_assert(sorted_colors[8].num == 12);// 9th is color #12.
    static_assert(sorted_colors[15].num == 1);//Last (brightest) is white. All match the computed order.
}