//Read whole file as a string		

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
	
	
	std::string whole_file;
	
	// Sets position to the end of the file (is needed, to reserve memory for string)
	is.seekg(0, std::ios::end);	
	
	// Reserves memory for the file (for tellg() positions)
	whole_file.reserve(is.tellg());//tellg() returns cur pos in string 
	
	// Sets position to the start of the file (coming back).
	is.seekg(0, std::ios::beg);
	
	// Sets contents of 'whole_file' to all characters in the file.
	whole_file.assign(std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>());
		std::cout <<  whole_file << '\n';

	std::ifstream f("file2.txt");
	if (f) {
		f.seekg(0, std::ios::end);
		const auto size = f.tellg();
		std::string str(size, ' ');
		f.seekg(0);
		f.read(&str[0], size);
		f.close();
		std::cout <<  str << '\n';
	}		
}