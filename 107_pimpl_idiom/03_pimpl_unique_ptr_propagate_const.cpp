// widget.h
class Widget {
// ... как раньше
    struct Impl;
    std::experimental::propagate_const<std::unique_ptr<Impl>> d_;
};
// widget.cpp
struct Widget::Impl { /*...*/ };
Widget::Widget(): d_(std::make_unique<Impl>()) {}
Widget::~Widget() {}

//Плюсы:
//соблюдение логической константности

//Минусы:
//возможность забыть создать Impl в конструкторе - no defalt C-tor
//propagate_const пока не является частью стандарта