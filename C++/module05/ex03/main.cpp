/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:28:39 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:28:40 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "==============================================" << std::endl;
    std::cout << "=============== Bureaucrats ==================" << std::endl;
    std::cout << "==============================================" << std::endl;
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 150);
    std::cout << alice << bob << std::endl;
    Intern intern;
    AForm* shrub = intern.makeForm("shrubbery creation", "home");
    if (shrub) {
        alice.signForm(*shrub);
        alice.executeForm(*shrub);
    }
    std::cout << std::endl;
    AForm* robo = intern.makeForm("robotomy request", "Marvin");
    if (robo) {
        alice.signForm(*robo);
        for (int i = 0; i < 3; ++i) {
            alice.executeForm(*robo);
        }
    }
    std::cout << std::endl;
    AForm* pardon = intern.makeForm("presidential pardon", "Ford");
    if (pardon) {
        alice.signForm(*pardon);
        alice.executeForm(*pardon);

    try {
        bob.executeForm(*pardon);
    } catch (const std::exception& e) {
        std::cerr << "Bob failed: " << e.what() << std::endl;
    }
}
    std::cout << std::endl;
    AForm* unknown = intern.makeForm("invalid form", "Nobody");
    delete shrub;
    delete robo;
    delete pardon;
    delete unknown;
    std::cout << "==============================================" << std::endl;
    return 0;
}
