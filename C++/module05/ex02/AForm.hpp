#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
class Bureaucrat;

#define HIGHEST_GRADE 1
#define LOWER_GRADE 150  

class AForm {

	public :
	AForm(const std::string name, const int gradeSign, const int gradeExec);
	AForm(const AForm &other);
	AForm& operator=(const AForm& src);

	//getters

	int getGradeSign() const;
	int getGradeExec() const;
	bool getIsSigned() const;
	std::string getName() const;

	void beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		public:
		virtual const char *what() const throw();
	};										
	
	class GradeTooLowException : public std::exception {
		public:
		virtual const char *what() const throw();
	};										

	~AForm();

	private :

	const std::string	_name;
	const int			_gradeSign;
	const int			_gradeExec;
	bool 				_isSigned;
	AForm(); //default constructor in private to avooid creating empty object

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);