//GPT5.1
//set_with_custom_allocator
#include <iostream>
#include <memory>  // For std::allocator_traits
#include <set>

// Simple custom stateless allocator (logs allocations/deallocations)
template <typename T>
struct CustomAllocator {
    using value_type = T;

    CustomAllocator() noexcept = default;

    template <typename U>
    CustomAllocator(const CustomAllocator<U>&) noexcept {std::cout << "Copy Ctor" <<'\n';}

    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n * sizeof(T) << " bytes\n";
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) noexcept {
        std::cout << "Deallocating " << n * sizeof(T) << " bytes\n";
        ::operator delete(p);
    }
    
};

// Example: Using CustomAllocator with std::set
int main() {
    std::set<int, std::less<int>, CustomAllocator<int>> mySet = {5, 1, 3, 2};    
    mySet.insert(4);
    
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << std::endl;    
}
