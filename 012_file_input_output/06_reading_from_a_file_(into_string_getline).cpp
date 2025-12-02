//Read whole file as a string using std::getline()		

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
	
	std::string str;	
	
	// The function getline returns false if there are no more lines
	for (std::string str; std::getline(is, str);) {
		std::cout << str << '\n';
	}	
}