/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:26:54 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:26:55 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "==============================================" << std::endl;
	std::cout << "=============  Bob tax form  =================" << std::endl;
	std::cout << "==============================================" << std::endl;

	Bureaucrat bob("Bob", 50);
	Form contract("Contract", 45, 30);
	bob.signForm(contract);

	std::cout << "==============================================" << std::endl;
	std::cout << "=============  Anne and the fine  ============" << std::endl;
	std::cout << "==============================================" << std::endl;

	Bureaucrat anne("Anne", 87);
	Form fine("Fine", 90, 45);
	anne.signForm(fine);

	std::cout << "==============================================" << std::endl;
	std::cout << "=============  Karen and the shop ============" << std::endl;
	std::cout << "==============================================" << std::endl;

	try {
		Bureaucrat Karen("Karen", 120);
		std::cout << Karen.getName() << " wants to send 120 euro to Colombia." << std::endl;
		Form Shop("Shop", 133, 133);
		Karen.signForm(Shop);
	} catch (const Form::GradeTooLowException& e) {
		std::cerr << "Error " << e.what() << std::endl;

	}

	std::cout << "==============================================" << std::endl;
	std::cout << "=============  End of the story   ============" << std::endl;
	std::cout << "==============================================" << std::endl;

	return 0;
}
