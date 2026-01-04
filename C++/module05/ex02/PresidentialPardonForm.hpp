#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	
	private : 
	PresidentialPardonForm();
	std::string _target;
	public:

	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
	void execute(Bureaucrat const & executor) const;
	const std::string& getTarget() const;
	virtual ~PresidentialPardonForm();
};