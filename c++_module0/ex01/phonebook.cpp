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



int main(void) {
	std::string prompt;
	while (true) {
		std::cout << "Choose an option between ADD SEARCH EXIT : ";
		std::getline(std::cin, prompt);
		if (prompt == "ADD" || prompt == "SEARCH" || prompt == "EXIT") {
			std::cout << "your choose : " << prompt << std::endl;
			break;
		}
		else {
		std::cout << "Invalid option : " << std::endl;
		}
	}

	
	return 0;
}