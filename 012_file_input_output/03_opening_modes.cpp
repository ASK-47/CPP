#include <iostream>
#include <fstream>

int main () {
	
	std::ifstream ifs; // ifstream: Opens file "foo.txt" for reading only.
	ifs.open("foo.txt", std::ios::in | std::ios::binary);//"in" = default for ifstream		
	
	std::ofstream ofs("foo.txt", std::ios::out | std::ios::trunc);//"out" = default for ofstream	
/*	
Mode	Meaning		For				Description
app		append		Output			Appends data at the end of the file
binary	binary		Input/Output	Input and output is done in binary
in		input		Input			Opens the file for reading
out		output		Output			Opens the file for writing
trunc	truncate	Input/Output	Removes contents of the file when opening
ate		at end		Input			Goes to the end of the file when opening
*/
}