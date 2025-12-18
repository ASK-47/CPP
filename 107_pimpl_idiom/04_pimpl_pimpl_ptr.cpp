// widget.h
class Widget {
// ... как раньше
    struct Impl;
    utils::PimplPtr<Impl> d_;
};
// widget.cpp
struct Widget::Impl { /*...*/ };
Widget::Widget() {}
Widget::~Widget() {}
