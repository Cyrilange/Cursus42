/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:59:10 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:59:10 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
int num;
std::string input;
std::cout << "Enter the number of zombies: ";
if (!std::getline(std::cin, input))
    return 1;
std::stringstream ss(input);
if (!(ss >> num) || num <= 0) {
    std::cout << "Invalid number" << std::endl;
    return 1;
}
std::cout << "Enter the name of the zombies (if you put a number and less name, the other will be called zombie+numero ): ";
if (!std::getline(std::cin, input))
    return 1;
Zombie* army = zombieHorde(num, input);
for (int i = 0; i < num; i++) {
    army[i].announce();
}
delete[] army;
return 0;

}