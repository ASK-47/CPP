#include <functional>  //gor std::invoke
#include <memory>

template <typename T>
class function;

template <typename Ret, typename... Param>
class function<Ret(Param... param)> {
   public:
    /*
    function(Ret (*f)(Param...))
        : callable(std::make_unique<callable_imp<Ret (*)(Param...)>>(f)) {}//for
    function pointers
    */

    /*
    template <typename Functionobject>
    function(Functionobject fo)
        : callable(std::make_unique<Functionobject>(fo)) {}//for function
    objects
    */

    template <typename Functionobject>
    function(Functionobject fo)
        : callable(std::make_unique<callable_imp<Functionobject>>(fo)) {
    }  // for function objects

    Ret operator()(Param... param) { return callable->call(param...); }
    // TODO  copy C-tor and plethora of other C-tors
    // TODO forwarding and unwrapper std::reference_wrapper

   private:
    struct callable_interface {
        virtual Ret call(Param...) = 0;
        virtual ~callable_interface() = default;
        // TODO  Ro5
        // TODO  virtual clone() function
    };

    template <typename Callable>
    struct callable_imp : callable_interface {
        callable_imp(Callable callable_) : callable(std::move(callable_)) {}
        /*Ret call(Param... param) { return callable(param...); }*/
        // or via std::invoke()
        Ret call(Param... param) { return std::invoke(callable, param...); }
        Callable callable;
    };

    std::unique_ptr<callable_interface> callable;
};

int f(int x, int y) { return x + y; }

int main() {
    function<int(int, int)> f1{[](int x, int y) { return x + y; }};
    function<int(int, int)> f2{f};
    return f1(1, 2) + f2(35, 4);
}