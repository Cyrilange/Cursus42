#pragma once 
#include "AForm.hpp"
class AForm;

class Intern {

public:

Intern();
Intern(const Intern& copy);
Intern& operator=(const Intern& copy);
AForm* makeForm(const std::string& nameForm, const std::string& targetForm) const;
~Intern();


};