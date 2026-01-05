/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:27:20 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:27:21 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	std::system("clear");
    std::srand(std::time(NULL));

    std::cout << CYAN << "==============================================" << RESET << std::endl;
    std::cout << CYAN << "=============== BUREAUCRAT TESTS =============" << RESET << std::endl;
    std::cout << CYAN << "==============================================" << RESET << std::endl;

    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        Bureaucrat charlie("Charlie", 50);

        std::cout << GREEN << alice << bob << charlie << RESET << std::endl;

        std::cout << YELLOW << "\n--- SHRUBBERY CREATION FORM ---" << RESET << std::endl;
        ShrubberyCreationForm shrub("home");
        alice.signForm(shrub);
        alice.executeForm(shrub);
        try { bob.executeForm(shrub); }
        catch (std::exception &e) { std::cerr << RED << "Bob failed: " << e.what() << RESET << std::endl; }

        std::cout << MAGENTA << "\n--- ROBOTOMY REQUEST FORM ---" << RESET << std::endl;
        RobotomyRequestForm robot("Marvin");
        alice.signForm(robot);
        for (int i = 0; i < 10; ++i) { 
			std::cout << MAGENTA << "\n" << i << " ---TESTS FOR ALICE ---" << RESET << std::endl;
			alice.executeForm(robot); 
		}
        RobotomyRequestForm robot2("Marvin2");
        try { alice.executeForm(robot2); }
        catch (std::exception &e) { std::cerr << RED << "Execute unsigned form: " << e.what() << RESET << std::endl; }

        std::cout << BLUE << "\n--- PRESIDENTIAL PARDON FORM ---" << RESET << std::endl;
        PresidentialPardonForm pardon("Ford");
        alice.signForm(pardon);
        alice.executeForm(pardon);
        try { bob.executeForm(pardon); }
        catch (std::exception &e) { std::cerr << RED << "Bob failed to execute pardon: " << e.what() << RESET << std::endl; }

        std::cout << CYAN << "\n--- COPY TESTS ---" << RESET << std::endl;
        RobotomyRequestForm robotCopy(robot);
        RobotomyRequestForm robotAssign("Temp");
        robotAssign = robot;
        alice.executeForm(robotCopy);
        alice.executeForm(robotAssign);

        std::cout << CYAN << "\n--- EDGE CASES ---" << RESET << std::endl;
        ShrubberyCreationForm edgeCase("office");
        try { charlie.executeForm(edgeCase); }
        catch (std::exception &e) { std::cerr << RED << "Charlie execute unsigned shrub: " << e.what() << RESET << std::endl; }
        charlie.signForm(edgeCase);
        charlie.executeForm(edgeCase);

    } catch (std::exception &e) {
        std::cerr << RED << "Exception caught in main: " << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << "\n==============================================" << RESET << std::endl;
    std::cout << CYAN << "=============== END OF TESTS =================" << RESET << std::endl;
    std::cout << CYAN << "==============================================" << RESET << std::endl;

    return 0;
}
