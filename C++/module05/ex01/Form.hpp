#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
class Bureaucrat;

#define HIGHEST_GRADE 1
#define LOWER_GRADE 150  

class Form {

	public :
	Form(const std::string name, const int gradeSign, const int gradeExec);
	Form(const Form &other);
	Form& operator=(const Form& src);

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

	~Form();

	private :

	const std::string	_name;
	const int			_gradeSign;
	const int			_gradeExec;
	bool 				_isSigned;
	Form(); //default constructor in private to avooid creating empty object

};

std::ostream& operator<<(std::ostream& os, const Form& obj);