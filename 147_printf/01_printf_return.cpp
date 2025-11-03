#include <iostream>

int main() {	
	char a[]="abcd";
	std::cout << "The total no of characters returned by " "printf() is " << printf("%s", a) << '\n';		
	    
    printf("The total no of characters returned by " "printf() is %d", printf("%s", a));
}