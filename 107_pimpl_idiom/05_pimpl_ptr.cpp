//https://habr.com/ru/articles/311038/
//pimpl_ptr

#ifndef MEMORY_PIMPL_PTR_H
#define MEMORY_PIMPL_PTR_H

#include <cassert>
#include <memory>
#include <print>

template<typename T>
class PimplPtr {
public:

    using ElementType = typename std::unique_ptr<T>::element_type;
   
    //защита от несозданного Impl - конструктор по умолчанию, который будет создавать Impl
    PimplPtr(T x): p_(std::make_unique <T>(x)) {//проверка/напоминалка в конструкторе:
         static_assert(sizeof(T) > 0, "Probably, you forgot to declare constructor explicitly");
         std::println("PimplPtr was created");
    }

    //Если у Impl нет конструктора по умолчанию, то компилятор скажет об этом, и пользователю потребуется другой конструктор    
    explicit PimplPtr(std::unique_ptr<T>&& p) noexcept: p_(std::move(p)) { assert(p_ != nullptr); }

    ~PimplPtr() {//проверка/напоминалка в деструкторе:
       static_assert(sizeof(T) > 0, "Probably, you forgot to declare destructor explicitly");
       std::println("PimplPtr was destroyed");
    }

    PimplPtr(const PimplPtr&) noexcept = delete;
    PimplPtr& operator =(const PimplPtr&) noexcept = delete;

    //чтобы сохранить семантику перемещения, надо добавить соответствующие конструктор и оператор
    PimplPtr(PimplPtr&&) noexcept = default;
    PimplPtr& operator =(PimplPtr&&) noexcept = default;


    const ElementType* get() const noexcept { return p_.get(); }
    const ElementType* operator->() const noexcept { return get(); }
    const ElementType& operator*() const noexcept { return *get(); }
    explicit operator const ElementType*() const noexcept { return get(); } //???

    ElementType* get() noexcept { return p_.get(); }
    ElementType* operator->() noexcept { return get(); }
    ElementType& operator*() noexcept { return *get(); }
    explicit operator ElementType*() noexcept { return get(); }
 
private:
   std::unique_ptr<T> p_; // <- Должен быть неконстантный для семантики перемещения
};

#endif // MEMORY_PIMPL_PTR_H


int main() { 
    PimplPtr p(10500);
}