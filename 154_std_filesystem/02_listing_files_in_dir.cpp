// https://www.geeksforgeeks.org/cpp/file-system-library-in-cpp-17/
// Listing Files in a Directory

#include <filesystem>
#include <iostream>

int main() {
    // Define the directory path to list files from
    std::filesystem::path directorypath = "DIR";

    // To check if the directory exists or not
    if (std::filesystem::exists(directorypath) && std::filesystem::is_directory(directorypath)) {
        // Loop through each item (file or subdirectory) in the directory
        for (const auto& entry : std::filesystem::directory_iterator(directorypath)) {            
            std::cout << "File: " << entry.path() << '\n';
        }
    } else {        
        std::cerr << "Directory not found." << '\n';
    }

    return 0;
}