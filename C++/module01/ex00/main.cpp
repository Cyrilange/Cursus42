/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:59:28 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:59:28 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

int main(void) {
    
    std::string prompt;
    std::cout << "enter a name: ";
    if (!std::getline(std::cin, prompt))
        return - 1; 
    std::cout << "\n";
    randomChump(prompt);
   
    return 0;
    
} 