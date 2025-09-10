#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>

class Contact {
    private:  
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        
        void Contact::fillContact();




};
        

class PhoneBook {
    private:
        Contact contacts[8];
        int count;
        int nextIndex;

    public:
    
};



#endif