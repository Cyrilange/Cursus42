/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:27:12 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:27:13 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) { std::cout << "Default constructor called" << std::endl;}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if ( grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if ( grade > 150)
		throw Bureaucrat::GradeTooLowException();		
	std::cout << "Bureaucrat " << name << " created." << " with grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << "Copy constructor called" << std::endl;
	std::cout << _name << " with grade " << _grade << std::endl;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn’t sign "
		          << form.getName() << " because "
		          << e.what() << std::endl;
	}
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	
	if(this != &other) {
		this->_grade = other._grade;
	}
	std::cout << "Copy assignment operator called\n";
	std::cout << "Bureaucrat: " << this->getName()
	<< " with grade: " << this->getGrade() << std::endl;
	return *this;
}

int Bureaucrat::getGrade() const { return this->_grade;}

const std::string Bureaucrat::getName() const {return this->_name;}

void Bureaucrat::setGrade(int grade) {
	if(grade < HIGHEST_GRADE) {throw Bureaucrat::GradeTooHighException(); }
	else if(grade > LOWER_GRADE) {throw Bureaucrat::GradeTooLowException(); }
	else {this-> _grade = grade;}
}

Bureaucrat::~Bureaucrat() { std::cout << "destructor called."<< std::endl; }

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too hight.\n";}

const char* Bureaucrat::GradeTooLowException::what() const throw() {return "Grade too low.\n"; }

void Bureaucrat::increment() {
	if(_grade - 1 < HIGHEST_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrement() {
	if(_grade + 1 > LOWER_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

void Bureaucrat::executeForm(AForm const &form) {
	form.execute(*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << " bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}
