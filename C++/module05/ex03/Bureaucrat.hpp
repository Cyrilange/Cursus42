#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"
class AForm;

#define HIGHEST_GRADE 1
#define LOWER_GRADE 150

class Bureaucrat {

	public: 

	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string getName() const;
	int getGrade() const;
	void setGrade(int _garde);
	void increment();
	void decrement();
	void signForm(AForm& form);
	void executeForm(AForm const &form);

	class GradeTooHighException : public std::exception {
		public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();

	};



	~Bureaucrat();

	private:

	std::string const _name;
	int _grade;



};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
