#include <iostream>
#include <fstream>

int main () {
    std::ofstream os("foo.txt");
    if(os.is_open()) {
        os << "Hello World!\n";
    }
	
	if(os.is_open()){
	char data[] = "Foo";
	// Writes 3 characters from data -> "Foo".
	os.write(data, 3);
	}
}