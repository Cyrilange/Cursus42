#ifndef CONTACT_HPP
#define CONTACT_HPP

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

#endif