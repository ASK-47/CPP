#include <iostream>
#include <memory>

class Shape {
   public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

template <typename T>
class ShapeModel : public Shape {
   public:
    explicit ShapeModel(T shape) : shape_(std::move(shape)) {}

    void draw() const override {
        shape_.draw();  // Предполагаем, что T имеет метод draw()
    }

   private:
    T shape_;
};

class ShapeWrapper {//just a unuque_ptr Wrapper for ShapeModel
   public:
    template <typename T>
    ShapeWrapper(T&& shape)
        : pImpl_(std::make_unique<ShapeModel<std::decay_t<T>>>(
              std::forward<T>(shape))) {}

    void draw() const { pImpl_->draw(); }

   private:
    std::unique_ptr<Shape> pImpl_;
};

struct Circle {
    void draw() const { std::cout << "Drawing Circle" << std::endl; }
};

struct Square {
    void draw() const { std::cout << "Drawing Square" << std::endl; }
};

int main() {
    ShapeWrapper c = Circle();
    ShapeWrapper s = Square();

    c.draw();
    s.draw();

    return 0;
}
