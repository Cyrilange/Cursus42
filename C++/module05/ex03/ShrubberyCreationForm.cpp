/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:29:04 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:29:05 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "Parametric constructor called(ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
: AForm(copy), _target(copy._target) {
    std::cout << "Copy constructor called(ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    std::cout << "Operator called = (ShrubberyCreationForm)" << std::endl;
    if (this != &copy) {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return *this;
}


const std::string& ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file) {
        std::cerr << "Error creating file: " << this->getTarget() << "shrubbery" << std::endl;
        return;
    }


    file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";
    
    file.close();
    std::cout << "Shrubbery created in file: " << this->getTarget() << "_shrubbery" << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor called(ShrubberyCreationForm)" << std::endl;
}
