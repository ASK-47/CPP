//https://t.me/easy_c_plus/1815
//chaining method
#include <iostream>
#include <list>
#include <vector>

class HashTable {
    int size;
    std::vector<std::list<int>> table;

   public:
    HashTable(int s) : size(s), table(s) {}

    int hashFunction(int key) { return key % size; }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            std::cout << i << ": ";
            for (int key : table[i]) {
                std::cout << key << " -> ";
            }
            std::cout << "NULL" << '\n';
        }
    }
};

int main() {
    HashTable ht(5);
    ht.insert(10);
    ht.insert(15);
    ht.insert(20);
    ht.insert(7);
    ht.insert(2);
    ht.display();
    return 0;
}
