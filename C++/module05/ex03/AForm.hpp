#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <fstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
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
	const std::string& getTarget() const;

	void beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		public:
		virtual const char *what() const throw();
	};										
	
	class GradeTooLowException : public std::exception {
		public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
		public:
		virtual const char* what() const throw();
		};
	
	virtual void execute(Bureaucrat const &executor) const = 0;

	virtual ~AForm();

	protected :

	const std::string	_name;
	const int			_gradeSign;
	const int			_gradeExec;
	bool 				_isSigned;

	private :
	AForm(); //default constructor in private to avooid creating empty object

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);