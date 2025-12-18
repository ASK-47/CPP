//https://t.me/grokaemcpp/788
//enable_shared_from_this

#include <functional>
#include <iostream>
#include <memory>

//=====UB=====
/*struct Task {
    int id;

    std::function<void()> GetNotifier() {
        return [&]{
            std::cout << "notify " << id << std::endl;
        };
    }
};
int main() {
    auto notify = Task { 5 }.GetNotifier();//temp object Task { 5 } was deleted
    notify();
}*/
//=====UB=====

struct Task : std::enable_shared_from_this<Task> { // inheriting provides shared_from_this()
    int id;

    Task(int x) : id(x) {}
    std::function<void()> GetNotifier() {        
        return [self = shared_from_this()] {// shared_from_this() generate additional std::shared_ptr instances pt1, pt2 etc. that all share ownership of Task 
            std::cout << "notify " << self->id << std::endl;
        };
    }
};

int main() {
    auto notify = std::make_shared<Task>(10500)->GetNotifier();// additional shared_ptr was created, temp object Task { 5 } was NOT deleted
    notify();  // Теперь безопасно - объект не будет уничтожен
}
