/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:59:38 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:59:38 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*This function creates a zombie, names it, and makes it announce itself.*/

void randomChump( std::string name ) {
    Zombie* newZ = newZombie(name);
    newZ->announce();
    usleep(100);
    delete newZ;
};
