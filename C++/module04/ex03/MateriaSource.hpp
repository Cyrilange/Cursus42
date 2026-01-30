/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:06:21 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/30 22:42:14 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;
class IMateriaSource;

class MateriaSource : public IMateriaSource{
	private : 
	AMateria* _materia[4];
	int materiaSize;

	public :
	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	MateriaSource& operator=(const MateriaSource& copy);
	~MateriaSource();
	virtual void learnMateria(const std::string& type);
	virtual AMateria* createMateria(const std::string& type);
	void printMateria() const;
	
	
};