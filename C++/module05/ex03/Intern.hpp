/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:28:35 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:28:36 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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