/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:53:26 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/30 00:57:05 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class Ice : public AMateria{
	Ice();
	Ice(const Ice& copy);
	Ice& operator=(const Ice& copy);
	AMateria* clone() const;
	void use(ICharacter& target);
	~Ice();
};