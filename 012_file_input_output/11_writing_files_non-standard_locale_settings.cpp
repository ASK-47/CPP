//Writing files with non-standard locale settings
#include <fstream>
#include <iostream>
#include <locale>

//Guidance for use:
//You should always apply a local to a stream before opening the file.
//Once the stream has been imbued you should not change the locale.
//Reasons for Restrictions: Imbuing a file stream with a locale has undefined behavior if the current locale is not state independent or not pointing at the beginning of the file.


int main() {
    std::cout << "User-preferred locale setting is "
              << std::locale("").name().c_str() << std::endl;
    // Write a floating-point value using the user's preferred locale.
    std::ofstream ofs1;
    ofs1.imbue(std::locale(""));
    ofs1.open("file11.txt");
    ofs1 << 78123.456 << std::endl;
    
	// Use a specific locale (names are system-dependent)
    //std::ofstream ofs2;
    //ofs2.imbue(std::locale("en_US.UTF-8"));
    //ofs2.open("file12.txt");
    //ofs2 << 78123.456 << std::endl;
    
	// Switch to the classic "C" locale
    std::ofstream ofs3;
    ofs3.imbue(std::locale::classic());
    ofs3.open("file13.txt");
    ofs3 << 78123.456 << std::endl;
}