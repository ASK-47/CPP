//Read whole file as a char array	

#include <iostream>
#include <fstream>

int main () {
	
	std::string filename ="foo.txt";
	
	std::ifstream is(filename);	
	if (!is.is_open()) {
		std::cerr << "Error opening file" << filename << std::endl;		
	} else {
		std::cout <<  "File " << filename << " is opened" << '\n';
	}
	
	char a[4];
	
	// Read 4 characters from the file.
	is.read(a, 4);	
	if (is.fail()) {
		std::cerr << "Error to read the file" << filename << std::endl;		
	}
	
	std::cout << a << '\n';
	
	std::string str(a);
	std::cout << str.substr(0,4) << '\n';	
}