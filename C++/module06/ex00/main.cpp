/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:04:29 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:04:30 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main() {
    std::cout << "===== Test CHAR =====" << std::endl;
    ScalarConverter::convert("a");
	std::cout << "==================================" << std::endl;
	ScalarConverter::convert("b");
	std::cout << "==================================" << std::endl;
	ScalarConverter::convert("c");
	std::cout << "==================================" << std::endl;
	ScalarConverter::convert("d");
	std::cout << "==================================" << std::endl;
	ScalarConverter::convert(" "); //space should be 32

    std::cout << "\n===== Test INT =====" << std::endl;
    ScalarConverter::convert("42");
	std::cout << "==================================" << std::endl;
    ScalarConverter::convert("-123");
    
    std::cout << "\n===== Test FLOAT =====" << std::endl;
    ScalarConverter::convert("4.2f");
	std::cout << "==================================" << std::endl;
    ScalarConverter::convert("-0.5f");

    std::cout << "\n===== Test DOUBLE =====" << std::endl;
    ScalarConverter::convert("3.14159");
	std::cout << "==================================" << std::endl;
    ScalarConverter::convert("-2.71828");

    std::cout << "\n===== Test PSEUDO-LITERALS =====" << std::endl;
    ScalarConverter::convert("nan");
	std::cout << "==================================" << std::endl;
    ScalarConverter::convert("nanf");
	std::cout << "==================================" << std::endl;
    ScalarConverter::convert("+inf");
	std::cout << "==================================" << std::endl;
    ScalarConverter::convert("+inff");
	std::cout << "==================================" << std::endl;
    ScalarConverter::convert("-inf");
	std::cout << "==================================" << std::endl;
    ScalarConverter::convert("-inff");

    std::cout << "\n===== Test INVALID =====" << std::endl;
    ScalarConverter::convert("hello");
	std::cout << "==================================" << std::endl;
    ScalarConverter::convert("123abc");

    return 0;
}
