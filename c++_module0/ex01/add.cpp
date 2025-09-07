#include "phonebook.hpp"

bool  is_validate_phone(std::string& number) {
	for (std::string::size_type i = 0; i < number.length(); i++) {
		if (!isdigit(number[i])) {
			return false;
		}
	}
	return true;
}

void fn_add(PhoneBook &pb) {
	std::string input;
	Contact& newContact = pb.get_current_contact();

	std::cout << "Enter first Name : " ;
	std::getline(std::cin, input);
	newContact.setFirstName(input);

	std::cout << "Enter last Name : " ;
	std::getline(std::cin, input);
	newContact.setLastName(input);

	std::cout << "Enter nickname : " ;
	std::getline(std::cin, input);
	newContact.setNickName(input);

	do {
		std::cout << "Enter phone number : " ;
		std::getline(std::cin, input);
		if (is_validate_phone(input) == false) {
			std::cout << "wrong number" <<std::endl;
		} else {
			break ;
		}
	}
	while (true);
	newContact.setPhoneNumber(input);

	std::cout << "Enter your darkest secret : " ;
	std::getline(std::cin, input);
	newContact.setDarkestSecret(input);
}