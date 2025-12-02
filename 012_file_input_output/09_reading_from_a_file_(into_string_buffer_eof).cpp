//Checking end of file inside a loop condition, bad practice?
//eof returns true only after reading the end of file. It does NOT indicate that the next read will be the end of stream!!! =>extra line

#include <iostream>
#include <fstream>
#include <sstream>

int main () {
	//BAD
	std::string buffer1;
	std::ifstream f("example.txt");	
	while (!f.eof()) {		
		f >> buffer1;// Read until EOF		
		std::cout << buffer1 << '\n';//=> extra 55555!!! WRONG
	}
	f.flush();
	
	//OK	
	while (!f.eof()) {		
		std::string buffer;
		f >> buffer >> std::ws;
		if (f.fail())//fail at ' ' or '\n'
			break;//=> no extra 55555!!! OK
		std::cout << buffer << '\n';
	}	
	
	//OK
	std::string buffer;
	std::ifstream f1("file.txt");	
	while (f1>>buffer>> std::ws) {		
		std::cout << buffer << '\n';
	}
	f1.flush();
	
	//BEST PRACTICE == std::getline()
	std::string line;	
	while (std::getline(f1, line)) {
		std::cout << line << '\n';
	}
	
}