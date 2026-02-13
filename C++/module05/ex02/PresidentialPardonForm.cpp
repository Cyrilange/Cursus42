/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:27:25 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:27:26 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target ) 
: AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Parametric constructor called(PresidentialPardonForm)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) 
: AForm(copy), _target(copy._target) {
	std::cout << "Copy constructor called(PresidentialPardonForm)" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	std::cout << "Operator called = (PresidentialPardonForm)" << std::endl;
	if(this != &copy) {
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return *this;
}

const std::string& PresidentialPardonForm::getTarget() const {
    return _target;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor called(PresidentialPardonForm)" << std::endl;
}