#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	
	private : 
	RobotomyRequestForm();
	std::string	_target;

	
	public:

	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
	void execute(Bureaucrat const & executor) const;
	const std::string& getTarget() const;
	virtual ~RobotomyRequestForm();
};