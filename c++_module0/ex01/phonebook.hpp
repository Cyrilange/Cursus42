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

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string darkestSecret;
		std::string	phoneNumber;


};

class PhoneBook {
	Contact contacts[8];
	//int		index;
};

#endif 