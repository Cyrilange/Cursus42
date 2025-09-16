/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:59:17 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:59:17 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sstream>

class Zombie {
    private:
    std::string	name;

	public: 
		void setName(std::string name) {  this->name = name;};
		std::string getName () const {return this->name;};
        Zombie();
		Zombie(std::string n);
		void announce( void );
		
		~Zombie();
		
};

Zombie* zombieHorde( int N, std::string name );

  

# endif