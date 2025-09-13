/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-06 15:31:25 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-06 15:31:25 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : index(0) {}
Contact::Contact() : 
			firstName(""),
			lastName(""),
			nickName(""),
			phoneNumber(""),
			darkestSecret("") 
			{}


PhoneBook::~PhoneBook() {}
Contact::~Contact() {}

std::string prompt_enter() {
	std::string prompt;
	while (true) {
		std::cout << "Choice : ADD SEARCH EXIT : ";
		if (!std::getline(std::cin, prompt)) {
			std::cout << "\nEnd of file" << std::endl;
			return "EXIT";
		}
		if (prompt == "ADD" || prompt == "SEARCH" || prompt == "EXIT") {
			
			break;
		}
		else {
		return "\0";
		}
	}
	return (prompt);
}

int main(void) {
	PhoneBook phonebook;
	while (true)
	{
		std::string input = prompt_enter();
		if (input == "ADD") {
			if (std::cin.eof()) {break ;}
			fn_add(phonebook);
			phonebook.next_index();
		}
		else if (input == "SEARCH") {
			search(phonebook);
		}
		else if (input == "EXIT")
			break;
		
	}	
	return 0;
}