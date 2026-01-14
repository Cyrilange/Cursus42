/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:03:52 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/14 20:39:19 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "===============TEST GIVEN BY 42================" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	

	std::cout << "===============TEST 1001 NUM================" << std::endl;
	std::srand(std::time(NULL));

	Span xp(1001);
	xp.generateNumbers(1001);

	std::cout << xp.shortestSpan() << std::endl;
	std::cout << xp.longestSpan() << std::endl;

	std::cout << "==============TEST LESS THAN 2=================" << std::endl;
	try {
		Span x(1);
		x.generateNumbers(1);
		std::cout << x.shortestSpan() << std::endl;
		std::cout << x.longestSpan() << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "==============TEST SIZE FULL=================" << std::endl;
	try {
		Span x(10);
		x.generateNumbers(11);
		std::cout << x.shortestSpan() << std::endl;
		std::cout << x.longestSpan() << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "===============================" << std::endl;

	return 0;
}

