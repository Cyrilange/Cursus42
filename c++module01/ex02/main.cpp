#include <iostream>
#include <string>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str; //pointer
    std::string& stringREF = str;  //ref
    std::cout << "Memory address of str : " << &str << std::endl;
    std::cout << "Memory address of stringPTR : " << &stringPTR << std::endl;
    std::cout << "Memory address of stringREF : " << &stringREF << std::endl;

    std::cout << "Value of str : " << str << std::endl;
    std::cout << "Value of stringPTR : " << stringPTR << std::endl;
    std::cout << "Value of stringREF : " << stringREF << std::endl;
    return 0;
}