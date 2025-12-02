// https://www.geeksforgeeks.org/cpp/file-system-library-in-cpp-17/
//  Creating a Directory and File

#include <filesystem>
#include <fstream>
#include <iostream>

int main() {
    // Define the path to create directory
    std::filesystem::path dir = "DIR";

    // To check if the directory exist or not, create it if doesn't exist
    if (!std::filesystem::exists(dir)) {
        std::filesystem::create_directory(dir);
        std::cout << "Directory created: " << dir << '\n';
    }

    // Define the file path within the directory and combining the directory
    std::filesystem::path file_path = dir / "new_file.txt";

    // Create and open the file for writing using std::ofstream
    std::ofstream file(file_path);
    if (file.is_open()) {
        // Write data to the file
        file << "It'a New File!!!";
        file.close();
        std::cout << "File created: " << file_path << '\n';
    } else {
        // Handle the case if any error occured
        std::cerr << "Failed to create file: " << file_path << '\n';
    }
    return 0;
}