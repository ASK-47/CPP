// https://t.me/cpp_geek/385
//  Оптимизация использования std::unordered_map в C++

#include <iostream>
#include <unordered_map>

struct MyKey {
    int x, y;

    bool operator==(const MyKey& other) const {
        return x == other.x && y == other.y;
    }
};

struct MyHash {
    size_t operator()(const MyKey& key) const {
        return std::hash<int>{}(key.x) ^ (std::hash<int>{}(key.y) << 1);
    }
};

int main() {
    std::unordered_map<MyKey, std::string, MyHash> my_map;
    my_map.reserve(10000);  // Подготавливаем место под 10,000 элементов

    std::unordered_map<std::string, int> data;
    std::string key = "long_key_string";
    data[key] = 100500;

    // int value = data[key]; // НЕ ЭФФЕКТИВНО: создаст пустую запись, если
    // ключа нет
    int value = data.at(key);  // БЫСТРЕЕ: выбросит исключение, если ключа нет
    std::cout << value << '\n';

    auto it = data.find(key);
    if (it != data.end()) {
        value = it->second;
    }
    std::cout << value + 100500 << '\n';
}
