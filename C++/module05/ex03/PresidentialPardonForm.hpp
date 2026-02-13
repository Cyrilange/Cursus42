/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:28:50 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:28:51 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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