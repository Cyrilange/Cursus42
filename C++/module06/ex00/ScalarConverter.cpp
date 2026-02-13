/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:04:36 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:04:37 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum Type {
CHAR,
INT,
DOUBLE,
FLOAT,
PSEUDO_FLOAT,
PSEUDO_DOUBLE,
TYPE_INVALID,
};

static Type detectType(const std::string& str) {
	bool hasDot = false;
	bool hasDigit = false;

	if (str.length() == 1 && !std::isdigit(str[0])) {return CHAR; }
	if (str == "nanf" || str == "+inff" || str == "-inff") {return PSEUDO_FLOAT; }
	if (str == "nan" || str == "+inf" || str == "-inf") {return PSEUDO_DOUBLE; }
	for(size_t i = 0; i < str.length(); i++) {
		if(str[i] == '.') {hasDot = true;}
		else if(std::isdigit(str[i])) {hasDigit = true;}
		else if(i == 0 && (str[i] == '-' || str[i == '+'])) {continue;}
		else {return TYPE_INVALID;}
	}
	if (hasDigit && hasDot && str[str.length() - 1] == 'f') {return FLOAT;}
	if (hasDot && hasDigit) {return DOUBLE;}
	if (hasDigit) {return INT;}
	return TYPE_INVALID;
}

static void display(double value, bool isPseudo = false) {
	
	std::cout << "char: ";
	if (isPseudo || value < 0 || value > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
	std::cout << "int: ";
	if (isPseudo || value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
	std::cout << "float: ";
	if (isPseudo)
		std::cout << (value != value ? "nanf" : (value < 0 ? "-inff" : "+inff"));
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	if (isPseudo)
		std::cout << (value != value ? "nan" : (value < 0 ? "-inf" : "+inf"));
	else
		std::cout << std::fixed << std::setprecision(1) << value;
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
	Type type = detectType(str);
	double value = 0;
	bool isPseudo = false;
	switch(type) {
		case CHAR:
			value = static_cast<double>(str[0]);
			break;
		case INT:
			value = static_cast<double>(std::atoi(str.c_str()));
			break;
		case FLOAT:
		case DOUBLE:
			value = std::atof(str.c_str());
			break;
		case PSEUDO_FLOAT:
		case PSEUDO_DOUBLE:
			isPseudo = true;
			if (str[0] == '-') value = -std::numeric_limits<double>::infinity();
			else if (str[0] == '+') value = std::numeric_limits<double>::infinity();
			else value = std::numeric_limits<double>::quiet_NaN();
			break;
		default:
			std::cerr << "Invalid input" << std::endl;
			return;
	}
	display(value, isPseudo);

}








//does nothing 

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
	return *this;
}