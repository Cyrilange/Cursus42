#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target ) 
: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Parametric constructor called(RobotomyRequestForm)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) 
: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), _target(copy._target) {

} 