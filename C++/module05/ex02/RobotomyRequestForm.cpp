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
	if(this != &copy) {
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor called(RobotomyRequestForm)" << std::endl;
}