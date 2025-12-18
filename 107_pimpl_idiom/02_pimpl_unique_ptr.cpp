// widget.h
class Widget {
public:
// ... как раньше
    void foo() const; // <- константный метод
private:
    struct Impl;
    std::unique_ptr<Impl> d_;
};
// widget.cpp
struct Widget::Impl { int i = 0; };
Widget::Widget(): d_(std::make_unique<Impl>()) {}
Widget::~Widget() {}

void Widget::foo() const {
    d_->i = 42; // <- изменение данных внутри константного метода
}

//Плюсы:
//защита от утечек памяти

//Минусы:
/нарушение логической константности