//https://t.me/easy_c_plus/1808
//resolving collisions


//1 Методы открытой адресации (Open Addressing)
#include <iostream>
#include <list>
#include <vector>

//1.1 Линейное пробирование (Linear Probing) 
//линейный поиск первой пустой ячейки, вставка в первую пустую ячейку
int hash(int key, int size) {
    return key % size;
}

int linear_probe(int key, int size, int table[]) {
    int index = hash(key, size);
    //Хешируем key1, попадаем в index = 3 → занято.  
    //Проверяем index = 4 → занято. 
    //Проверяем index = 5 → свободно, вставляем!
    // Двигаемся вперёд шаг за шагом
    while (table[index] != -1) { // -1 означает пустую ячейку
        index = (index + 1) % size; // Двигаемся вперёд
    }
    return index;
}

//1.2 Квадратчиное пробирование (Quadratic probing) 
int quadratic_prob(int key, int size, int table[]) {
    int index = hash(key, size);        
    //Идём по квадратичному шагу: +1², +2², +3², …  
    while (table[index] != -1) { // -1 означает пустую ячейку
        index = (hash(key, size) + index*index) % size; 
    }   
    return index;
}

//1.3 Двойное хеширование (Double Hashing)

int hash1(int key, int size) {
    return key % size;
}

int hash2(int key, int size) {
    return key % 2*size;
}


int double_hash(int key, int size, int table[]) {
    int index = hash(key, size);
    
    while (table[index] != -1) { // -1 означает пустую ячейку
        index = (hash1(key, size) + index * hash2(key, size)) % size; 
    }   
    return index;
}

//2 Методы цепочек (Chaining)
class HashTable {
    int size;
    std::vector<std::list<int>> table;   
public:
    HashTable(int s) : size(s), table(s) {}

    void insert(int key) {
        int index = key % size;
        table[index].push_back(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            std::cout << i << ": ";
            for (int num : table[i])
                std::cout << num << " -> ";
            std::cout << "NULL\n";
        }
    }
};


//3 Хеширование с ко-хешированием (Coalesced Hashing)
//Комбинация цепочек и открытой адресации:  
//В таблице хранятся указатели на следующий элемент с таким же хешем.  
//Не требует выделения памяти для списков.

int main() {
    HashTable ht(5);
    ht.insert(10);
    ht.insert(15);
    ht.insert(20);
    ht.insert(25);
    ht.display();
}