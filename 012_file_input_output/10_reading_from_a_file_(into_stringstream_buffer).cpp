//Read whole file int stringstream buffer

#include <iostream>
#include <fstream>
#include <sstream>

int main () {
	std::ifstream f("file.txt");
	if (f) {
		std::stringstream buffer;
		buffer << f.rdbuf();//The rdbuf() method returns a pointer to a streambuf that can be pushed into buffer via the stringstream::operator<< member function.
		f.close();
		// The content of "file.txt" is available in the string `buffer.str()`
		std::cout << buffer.str() << '\n';
	}

	std::ifstream f1("file1.txt");
	if (f1)	{
	std::string str((std::istreambuf_iterator<char>(f1)), std::istreambuf_iterator<char>());//
		std::cout << str << '\n';
	}
	//NOTE: the extra parentheses around the first argument to the string constructor are essential to prevent the most vexing parse problem.
}