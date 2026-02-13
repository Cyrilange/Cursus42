/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:54:38 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:54:38 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Aanimal("Dog") {
    std::cout << this->getType() << " Default contructor called" << std::endl;
    this->brain = new Brain();
    }
    
    Dog::Dog(const Dog& other) : Aanimal("Dog") {
        std::cout << this->getType() << " Copy contructor called" << std::endl;
        this->brain = new Brain(*other.brain);
    }
    
    void Dog::makeSound() const {
        std::cout << BOLD_PINK << "Woaf Woaf" << RESET << std::endl;
    }

    Aanimal& Dog::operator=(const Dog& other) {
        if (this != &other) {
            Aanimal::operator=(other);
            *this->brain = *other.brain;
        }
        return *this;
    }

    Brain& Dog::getBrain() const {
        return *brain;
    }
    
    Dog::~Dog() {
    std::cout << "Destructor  " << this->getType() << std::endl;
    delete brain;
    }