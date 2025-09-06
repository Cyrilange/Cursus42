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

std::string prompt_enter() {
	std::string prompt;
	while (true) {
		std::cout << "Choose between ADD SEARCH EXIT : ";
		std::getline(std::cin, prompt);
		if (prompt == "ADD" || prompt == "SEARCH" || prompt == "EXIT") {
			std::cout <<  prompt << std::endl;
			break;
		}
		else {
		std::cout << "Invalid option : " << std::endl;
		}
	}
	return (prompt);
}

int main(void) {
	std::string input = prompt_enter();
	Contact phonebook;
	if (input == "ADD") {
		std::cout << "Enter first Name :" << std::endl;
		std::cin >> phonebook.firstName;
		std::cout << "Enter last Name :" << std::endl;
		std::cout << "Enter nickname :" << std::endl;
		std::cout << "Enter phone number :" << std::endl;
		std::cout << "Enter your darkest secret :" << std::endl;
	}


	
	return 0;
}