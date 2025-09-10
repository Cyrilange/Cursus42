#include "phonebook.hpp"
#include <iostream>
#include <string>


void Contact::fillContact()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, this->firstName);

    std::cout << "Enter last name: ";
    std::getline(std::cin, this->lastName);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, this->nickName);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, this->phoneNumber);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, this->darkestSecret);  
}


int main(void)
{
    PhoneBook phonebook;
    std::string command;

    while(true)
    {
        std::cout << "Enter the command (ADD , SEARCH , EXIT)" << std::endl;
        std::getline(std::cin , command);

        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContact();
        }
        else if (command == "EXIT")
            break ;
    }

    return 0;
}w5