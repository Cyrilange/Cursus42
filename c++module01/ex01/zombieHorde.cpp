/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:59:21 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:59:21 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    if (N <= 0)
        return NULL;
    Zombie* horde = new Zombie[N];
    std::stringstream str(name);
    std::string s;
    for (int i = 0; i < N; i++) {
        if ((str >> s))
            horde[i].setName(s);
        else {
            std::stringstream zombie;
            zombie << "zombie_" << (i + 1);
            horde[i].setName(zombie.str());
        }
    }
    return horde;
}
