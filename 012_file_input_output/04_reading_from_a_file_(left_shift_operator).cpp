//Read file Step by step using operator >>
//Need to know how the data is formatted
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
	
	std::string firstname, lastname;	
	int age, bmonth, bday, byear;	
	
	// Note: '>>' returns false if it reached EOF (end of file) or if the input data doesn't correspond to the type of the input variable
	while (is >> firstname >> lastname >> age >> bmonth >> bday >> byear) {
		std::cout <<  firstname << ' ' << lastname << ' ' << age << ' ' << bmonth << ' ' << bday << ' ' << byear << '\n';	
	};	
}