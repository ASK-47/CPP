// C++ program to demonstrate example of tellg() function.
#include <bits/stdc++.h>

int main() {
    
    std::string str1 = "123456789";
    std::istringstream in1(str1);
    std::string word1;
    in1>> word1;
    //After reading the word "123456789" tellg() returns -1 == failure.
    std::cout << "After reading the word \"" << word1 << "\" tellg() returns "<< in1.tellg() << '\n';
    
    std::string str2 = "123456789 ";
    std::istringstream in2(str2);
    std::string word2;
    in2>> word2;//>> is stoped on ' '
    //After reading the word "123456789" tellg() returns 9 == cur pos in istringstream std::istringstream
    std::cout << "After reading the word \"" << word2 << "\" tellg() returns "<< in2.tellg() << '\n';
}