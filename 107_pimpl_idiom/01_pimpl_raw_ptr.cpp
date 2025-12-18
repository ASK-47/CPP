// widget.h
class Widget {
public:
    Widget();
//... отсутствует деструктор
private:
    struct Impl;
    std::auto_ptr<Impl> d_;
};
// widget.cpp
struct Widget::Impl { /*...*/ };
Widget::Widget(): d_(new Impl) {}

//Плюсы:
//безопасен относительно исключений
//Минусы:
//запрещен
//возможна утечка памяти при удалении неполного класса