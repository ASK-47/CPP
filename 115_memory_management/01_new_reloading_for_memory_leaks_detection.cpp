//https://t.me/cplusplus_tg/2884
//DO NOT WORK TODO!!!
#include <iostream>
#include <map>

std::map<void*, size_t> allocations;

void* operator new (size_t size) {
	//void* ptr= ::operator new(size);
	void* ptr=malloc(size);
	//allocations[ptr]=size;//???? DO NOT WORK TODO!!!
	std::cout << "Allocated " << size << " bytes at " << ptr << '\n';
	return ptr;	
}

void operator delete (void* ptr) noexcept {//DO NOT WORK TODO!!!
	if (allocations.find(ptr) != allocations.end()) {
		std::cout << "Defllocated " << allocations[ptr] << " bytes at " << ptr << '\n';
		allocations.erase(ptr);
	}
	free(ptr);
}

int main() {		
	int* a=new int (5);	
	double* b=new double (10.5);
		
	delete a;
	//no delete b - memory leak!!!	
	
	if (!allocations.empty()) {
		std::cout << "Memory leak detected" << '\n';
	}	
}