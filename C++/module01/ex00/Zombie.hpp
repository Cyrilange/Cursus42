/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:59:46 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:59:46 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>


class Zombie {
    private:
    std::string	name;

	public: 
		std::string setName(std::string name);
		std::string getName () const;

		Zombie(std::string n);
		Zombie();
		~Zombie();
		void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif