#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	
	private : 
	ShrubberyCreationForm();
	std::string _target;
	
	public:

	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
	void execute(Bureaucrat const & executor) const;
	const std::string& getTarget() const;
	virtual ~ShrubberyCreationForm();
};