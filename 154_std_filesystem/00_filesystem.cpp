#include <filesystem>
#include <fstream>
#include <iostream>

int main() {
	
	//CREATE DIR
	std::filesystem::path dir_path = "DIR0";
	
    if (!std::filesystem::exists(dir_path)) {
        std::filesystem::create_directory(dir_path);
        std::cout << "Directory was created" << '\n';
    }

	
	//CREATE FILE IN DIR
    std::filesystem::path file_path = dir_path / "file.txt";    
    std::ofstream file(file_path);
    if (file.is_open()) {        
        file << "It'a New File!!!";
        file.close();
        std::cout << "File created: " << file_path << '\n';
    } else {        
        std::cerr << "Failed to create file: " << file_path << '\n';
    }
	
	
	//LIST FILES IN DIR
    for (const auto& entry : std::filesystem::directory_iterator(dir_path)) {
        std::cout << "Found " << entry.path() << '\n';
    }
	
	//COPY FILE
	std::filesystem::path from_path = dir_path/"file.txt"; 
	std::filesystem::path to_path = "DIR/file.txt"; 
    std::filesystem::copy (from_path, to_path);
    std::cout << "file was copied " << '\n';
	
	//FILE SIZE
    std::cout << std::filesystem::file_size(to_path) << " bytes" << '\n';
	
	//RENAME
	std::filesystem::path ini_file_path = "DIR0/file.txt"; 
	std::filesystem::path copy_file_path = "DIR0/06_file.txt"; 
    std::filesystem::rename (ini_file_path, copy_file_path);
    std::cout << "file was renamed" << '\n';
}