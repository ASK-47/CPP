//https://t.me/easy_c_plus/1794
//map rehash
#include <iostream>
#include <list>
#include <vector>

class HashTable {
   private:
    int currentSize;
    int numberOfElements;
    double loadFactorThreshold;
    std::vector<std::list<std::pair<int, std::string>>> table;

    void rehash() {
        //int oldSize = currentSize;
        currentSize *= 2;  // Увеличиваем размер таблицы
        std::vector<std::list<std::pair<int, std::string>>> newTable(
            currentSize);

        for (const auto& list : table) {
            for (const auto& [key, value] : list) {
                int hashValue = key % currentSize;
                newTable[hashValue].emplace_back(key, value);
            }
        }

        table = std::move(newTable);
    }

   public:
    HashTable(int size = 10, double threshold = 0.75) : currentSize(size), numberOfElements(0), loadFactorThreshold(threshold) {
        table.resize(currentSize);
    }

    int hashFunction(int key) { return key % currentSize;}

    void insertItem(int key, std::string value) {
        int hashValue = hashFunction(key);
        table[hashValue].emplace_back(key, value);
        numberOfElements++;
        // Проверяем, нужно ли выполнять рехеширование
        if (static_cast<double>(numberOfElements) / currentSize >
            loadFactorThreshold) {
            rehash();
        }
    }

    void displayTable() {
        for (int i = 0; i < currentSize; i++) {
            if (!table[i].empty()) {
                std::cout << "Bucket " << i << ": ";
                for (auto& [key, value] : table[i]) {
                    std::cout << "[" << key << ": " << value << "] ";
                }
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    ht.insertItem(1, "one");
    ht.insertItem(2, "two");
    ht.insertItem(11, "eleven");  // Триггер рехеширования при необходимости

    ht.displayTable();
    // Вывод:
    // Bucket 1: [1: one]
    // Bucket 2: [2: two]
    // Bucket 11: [11: eleven]
}
