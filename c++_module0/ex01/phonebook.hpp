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

#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include <iostream>
#include <ctype.h>
#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string	phoneNumber;
		std::string darkestSecret;


	public:
		Contact();
		~Contact();

	       //set 
		void setFirstName(const std::string& value) {this->firstName = value;};
		void setLastName(const std::string& value) {this->lastName = value;};
		void setNickName(const std::string& value) {this->nickName = value;};
		void setPhoneNumber(const std::string& value) {this->phoneNumber = value;};
		void setDarkestSecret(const std::string& value) {this->darkestSecret = value;};

			//get
		std::string getFirstName() const {return this->firstName;}
		std::string getLastName() const {return this->lastName;}
		std::string getNickName() const {return this->nickName;}
		std::string getPhoneNumber() const {return this->phoneNumber;}
		std::string getDarkestSecret() const {return this->darkestSecret;}
};

class PhoneBook {
	private:
		Contact contacts[8];
		int		index;
	public:
		PhoneBook();
		~PhoneBook();

		Contact& get_current_contact() {
            return this->contacts[this->index];
        }
};


bool  is_validate_phone(std::string& number);
void fn_add(PhoneBook &pb);

#endif 