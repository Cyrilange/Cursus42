/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:54:47 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:54:47 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#define PINK_BOLD_ITALIC "\033[1;3;95m"
#define RESET "\033[0m"
#define YELLOW "\033[1;33m"
#define PINK "\033[1;35m"


int main() {
    Dog a;
    Cat b;

    b.makeSound();
    a.makeSound();

    a.getBrain();

    Dog* j = new Dog();
    j->getBrain().setIdea(1, "hello");
    std::cout << YELLOW << j->getType() << RESET << " ideas: ";
    std::cout << YELLOW << j->getBrain().getIdea(1) << RESET << std::endl;

    delete j;

    return 0;
}