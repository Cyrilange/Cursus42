#include "Form.hpp"

Form::Form(const std::string name, const int gradeSign, const int gradeExec) 
: _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _isSigned(false) 
{
	std::cout << "Parametric constructor called" << std::endl;
	if (gradeSign < HIGHEST_GRADE || gradeExec < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (gradeSign > LOWER_GRADE || gradeExec > LOWER_GRADE)
		throw Form::GradeTooLowException();
	std::cout << "Form " << this->getName() << " with grade to sign "
	<< this->getGradeSign() << " and grade to execute " << this->getGradeExec() << std::endl;
	
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Error: Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Error: Grade is too high";
}

Form::Form(const Form &other)
: _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec), _isSigned(false) 
{
	std::cout << "Copy constructor for the form " << this->getName() << std::endl;
}

Form& Form::operator=(const Form& src) {
	if(this != &src) {
		this->_isSigned = src._isSigned;
	}
	return *this;
}
void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();

	this->_isSigned = true;
}


//getters

int Form::getGradeSign() const {
	return this->_gradeSign;
}
int Form::getGradeExec() const {
	return this->_gradeExec;
}
bool Form::getIsSigned() const {
	return this->_isSigned;
}
std::string Form::getName() const {
	return this->_name;
}

Form::~Form() {
	std::cout << "Destructor called to " << this->getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << "Form name: " << obj.getName() << '\n'
	   << "Grade required to sign: " << obj.getGradeSign() << '\n'
	   << "Grade required to execute: " << obj.getGradeExec() << '\n'
	   << "Signed: " << (obj.getIsSigned() ? "yes" : "no");
	return os;
}
