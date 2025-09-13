/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-06 15:31:21 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-06 15:31:21 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <ctype.h>
#include <string>
#include "contact.hpp"
#include <iomanip>
#define yl  "\033[1;33m"
#define rst "\033[0m"



class PhoneBook {
	private:
		Contact contacts[8];
		int		index;
	public:
		PhoneBook();
		~PhoneBook();

		static bool is_validate_phone(const std::string& number);

		Contact& get_current_contact() {
            return this->contacts[this->index];
        }

		Contact& get_contact(int i) {
			return contacts[i];
		}

		void next_index() {
			this->index = (this->index + 1) % 8;
		}

		std::string format_cell(const std::string &s) {
			if (s.length() > 10)
				return s.substr(0, 9) + ".";
			return std::string(10 - s.length(), ' ') + s;
		}

		void display() {
			std::cout << yl << std::right << std::setw(10) << "Index" << rst << "|"
					  << yl << std::right << std::setw(10) << "First Name" << rst << "|"
					  << yl << std::right << std::setw(10) << "Last Name" << rst << "|"
					  << yl << std::right << std::setw(10) << "Nickname" << rst << "|\n";
		
			for (int i = 0; i < 8; i++) {
				Contact &c = contacts[i];
				if (c.getFirstName().empty() && c.getLastName().empty()) continue;
		
				std::cout << std::right << std::setw(10) << i << "|"
						  << format_cell(c.getFirstName()) << "|"
						  << format_cell(c.getLastName()) << "|"
						  << format_cell(c.getNickName()) << "|\n";
			}
		}
		

};


void fn_add(PhoneBook &pb);
void search(PhoneBook &pb);

#endif 