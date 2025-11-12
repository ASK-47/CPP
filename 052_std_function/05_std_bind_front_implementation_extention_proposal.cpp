//https://youtu.be/9laCL5GixNk
//Pushing it further - extension on set of Constexprs
#include <functional>

int add(int x, int y) {
  return x + y;
}

void use(const auto &f);


template<auto Func, auto ... Constexprs, typename... Param>
constexpr auto bind_front(Param && ... param) {
  if constexpr (sizeof...(param) == 0) {
    return []<typename ... Inner>(Inner && ... inner) static {
      return Func(Constexprs..., std::forward<Inner>(inner)...);
    };
  } else {
    return [...param = std::forward<Param>(param)]<typename ... Inner>(Inner && ... inner) {
      return Func(Constexprs..., param..., std::forward<Inner>(inner)...);
    };
  }
}

int main()
{
  const auto bound = bind_front<add, 3, 3>();
  return bound();
}

