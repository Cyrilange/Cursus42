/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:28:31 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:28:32 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern() {
	std::cout << "Default constructor intern called" << std::endl;
}
Intern::Intern(const Intern& copy) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}
Intern& Intern::operator=(const Intern& copy) {
	std::cout << "Operator= called Intern" << std::endl;
	if(this == &copy)
		return *this;
	return *this;
}

static AForm* createShrubbery(const std::string& t) { return new ShrubberyCreationForm(t); }

static AForm* createRobotomy(const std::string& t) { return new RobotomyRequestForm(t); }

static AForm* createPresidential(const std::string& t) { return new PresidentialPardonForm(t); }


AForm* Intern::makeForm(const std::string& nameForm, const std::string& targetForm) const {
    struct FormPair {
        std::string name;
        AForm* (*create)(const std::string& target);
    };

	FormPair forms[] = {
		{ "shrubbery creation", createShrubbery },
		{ "robotomy request",   createRobotomy },
		{ "presidential pardon",createPresidential }
	};

    for (int i = 0; i < 3; ++i) {
        if (nameForm == forms[i].name) {
            AForm* f = forms[i].create(targetForm);
            std::cout << "Intern creates " << nameForm << std::endl;
            return f;
        }
    }

    std::cerr << "Intern error: form \"" << nameForm << "\" does not exist!" << std::endl;
    return 0;
}
Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}