#include <iostream>
#include <functional>

struct Person {
    std::string name;
    int age;

    bool operator==(const Person& other) const {
        return name==other.name && age==other.age;
    }

    bool operator!=(const Person& other) const {
        return !(*this==other);
    }
};

template<>
struct std::hash<Person> {//специализации std::hash для Person
    std::size_t operator() (const Person& p) {
        std::size_t name_hash=std::hash<std::string>{}(p.name);
        std::size_t age_hash=std::hash<int>{}(p.age);
        return name_hash^age_hash;
    }
};

int main () {
    Person person{"Andrey Kuznetsov", 45};
    std::hash<Person> person_hasher;//хэш-функция для Person
    std::size_t hash_value=person_hasher(person);//вычисляем хэш-значение
    std::cout<< "Hash value=" << hash_value << '\n';
}
