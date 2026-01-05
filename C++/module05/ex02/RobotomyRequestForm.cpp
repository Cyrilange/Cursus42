/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:27:34 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:27:35 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target ) 
: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Parametric constructor called(RobotomyRequestForm)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) 
: AForm(copy), _target(copy._target) {
	std::cout << "Copy constructor called(RobotomyRequestForm)" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	std::cout << "Operator called = (RobotomyRequestForm)" << std::endl;
	if(this != &copy) {
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return *this;
}

const std::string& RobotomyRequestForm::getTarget() const {
    return _target;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;

    if (std::rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->getTarget() << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor called(RobotomyRequestForm)" << std::endl;
}