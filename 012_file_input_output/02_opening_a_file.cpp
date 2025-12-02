#include <iostream>
#include <fstream>

class CustomException {
public: 
    CustomException(const std::string& message): message{message}{}
    std::string getMessage() const {return message;}

private:    
	std::string message;	
};


int main () {
	
	std::string filename = "Test.txt"; //Error - no file Test.txt
	//std::string filename = "foo.txt";
	
    //1 You can open the file directly in the constructor:
	std::ifstream ifs(filename); // ifstream: Opens file "foo.txt" for reading only.
	//Check for opening
	if (!ifs.is_open()) {
		//std::cerr << "Error opening file: " << filename << std::endl;
		try {throw CustomException("File could not be opened!!!").getMessage();
		} catch (std::string& message) {
			std::cout << message << '\n';
		}
	} else {
		std::cout <<  "File " << filename << " is opened" << '\n';
	}	
	
	
	std::ofstream ofs("foo.txt"); // ofstream: Opens file "foo.txt" for writing only
	
	//2 Alternatively, you can use the file stream's member function open():
	std::ifstream ifs2;
	ifs2.open("bar.txt"); // ifstream: Opens file "bar.txt" for reading only.
	
	std::ofstream ofs2;
	ofs2.open("bar.txt"); // ofstream: Opens file "bar.txt" for writing only.
	
	std::fstream iofs2;
	iofs2.open("bar.txt"); // fstream: Opens file "bar.txt" for reading and writing.
	
	
	std::string filename3 = "foo.txt";
	
	// Open the file 'g:\R\CPP\012_file_input_output\foo.txt\foo.txt' on Windows.
	std::ifstream ifs3(R"(g:\R\CPP\012_file_input_output\foo.txt)"); // using raw literal
	if (!ifs3.is_open()) {
		std::cerr << "Error opening file: " << filename3 << std::endl;		
	} else {
		std::cout <<  "File " << filename3 << " is opened" << '\n';
	}

	// Open the file 'f:\ДАННЫЕ\moo.txt' on Windows.
	//TODO
	//std::ifstream ifs4(LR"(f:\ДАННЫЕ\moo.txt)"); // using wide characters with raw literal	
	
}