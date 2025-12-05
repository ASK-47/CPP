// https://t.me/cpp_ready/1693
// defer - object that automatically close the file (or DO somthing else) at the end of the scope

#include <iostream>

template <typename F>
class Defer {
   public:
    explicit Defer(F&& f) : func_(std::forward<F>(f)) {}
    Defer(const Defer&) = delete;
    Defer& operator=(const Defer&) = delete;
    ~Defer() { func_(); }

   private:
    F func_;
};
template <typename F>
Defer<F> make_defer(F&& f) {
    return Defer<F>{std::forward<F>(f)};
}

int main() {
    std::FILE* f = std::fopen("data.txt", "w");
    if (!f) {
        std::perror("fopen");
        return 1;
    }

    //Object that automatically close the file at the end of the scope
    auto close_file = make_defer([&] {
        std::puts("closing file...");
        std::fclose(f);
    });

    std::puts("writing...");
    std::fputs("hello\n", f);
    
    if (std::ferror(f)) {
        std::puts("write error");
        return 1;  // defer всё равно сработает
    }
    std::puts("ok");
    return 0;  // здесь тоже автоматически закроем файл
}
