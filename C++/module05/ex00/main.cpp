/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:26:29 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:26:30 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//interisting thing about the destructor , if you create an object outside
//of the try catch it will be destroy at the end , otherwise inside the try catch

int main() {
	std::cout << "==============================================" << std::endl;
	std::cout << "=============  Alice and Joseph  =============" << std::endl;
	std::cout << "==============================================" << std::endl;
    try {
        Bureaucrat Alice("Alice", 11);
		Bureaucrat Joseph("Joseph", 0);
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
	std::cout << "==============================================" << std::endl;
	std::cout << "=================  Ania   ====================" << std::endl;
	std::cout << "==============================================" << std::endl;

	Bureaucrat q("Ania", 26);
	Bureaucrat w(q);
	Bureaucrat e = w;

	std::cout << std::endl;

	std::cout << "q: " << q;
	std::cout << "w: " << w;
	std::cout << "e: " << e;
	std::cout << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "==================  Elias   ==================" << std::endl;
	std::cout << "==============================================" << std::endl;

	Bureaucrat i("Elias", 3);
	Bureaucrat c(i);
	Bureaucrat p = i;

	std::cout << std::endl;

	std::cout << "i: " << i;
	std::cout << "c: " << c;
	std::cout << "p: " << p;
	std::cout << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "==================  Cyril   ==================" << std::endl;
	std::cout << "==============================================" << std::endl;
	Bureaucrat cyril("Cyril", 149);
	try {
		cyril.decrement();
		std::cout << "- 1 points" << std::endl;
		cyril.decrement();
		std::cout << "- 1 points" << std::endl;
		
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	
	std::cout << "==============================================" << std::endl;
	std::cout << "==================  Julia   ==================" << std::endl;
	std::cout << "==============================================" << std::endl;

	try {
		Bureaucrat Julia("Julia", 2);
		std::cout << "Now we will add 2 pts for Julia" << std::endl;
		Julia.increment();
		Julia.increment();
	}
	catch(const std::exception &e) {
		std::cerr << "Exeption caught: " << e.what() << std::endl;
	}
	

	std::cout << "==============================================" << std::endl;
}
