/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:53:41 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:53:41 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define PINK_BOLD_ITALIC "\033[1;3;95m"
#define RESET "\033[0m"


int main()
{
std::cout << PINK_BOLD_ITALIC << "TEST WITH ANIMAL" << RESET << std::endl;
std::cout << "\n";
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;


std::cout << "\n";
std::cout << PINK_BOLD_ITALIC << "TEST WITH WRONG ANIMAL" << RESET << std::endl;
std::cout << "\n";
const WrongAnimal* arr[2];
arr[0] = new WrongCat();
arr[1] = new WrongAnimal();

for (int i = 0; i < 2; ++i) {
    arr[i]->makeSound();
}

for (int i = 0; i < 2; ++i) {
    delete arr[i];
}

return 0;
}