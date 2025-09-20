/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-20 14:19:36 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-20 14:19:36 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
This function creates a zombie
My choice is to use the heap with the new and delete*/

Zombie* newZombie( std::string name ) {
    Zombie* newZ = new Zombie(name); 
    return newZ;
};