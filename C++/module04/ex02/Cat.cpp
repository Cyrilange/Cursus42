/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:54:29 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:54:29 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Aanimal("Cat") {
std::cout << this->getType() << " Default contructor called" << std::endl;
this->brain = new Brain();

}

Cat::Cat(const Cat& other) : Aanimal("Cat") {
    std::cout << this->getType() << " Copy contructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Aanimal& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Aanimal::operator=(other); 
        *this->brain = *other.brain;
    }
    return *this;
}

Brain& Cat::getBrain() const {
    return *brain;
}

void Cat::makeSound() const  {
    std::cout << BOLD_YELLOW << "Meow Meow" << RESET << std::endl;
}

Cat::~Cat() {
std::cout << "Destructor  " << this->getType() << std::endl;
delete brain;
}