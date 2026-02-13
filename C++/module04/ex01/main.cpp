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
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE; i++) {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

 
    Dog* d1 = dynamic_cast<Dog*>(animals[0]);
    Dog* d2 = dynamic_cast<Dog*>(animals[1]);
    Cat* c1 = dynamic_cast<Cat*>(animals[2]);
    Cat* c2 = dynamic_cast<Cat*>(animals[3]);

    if (d1) {
        d1->getBrain().setIdea(0, "Eat bones");
        d1->getBrain().setIdea(1, "Play fetch");
        d1->getBrain().setIdea(2, "Chase cat");
        d1->getBrain().setIdea(3, "Nap");
        d1->getBrain().setIdea(4, "Bark at mailman");
    }
    if (d2) {
        d2->getBrain().setIdea(0, "Dig hole");
        d2->getBrain().setIdea(1, "Chew shoe");
        d2->getBrain().setIdea(2, "Sleep");
        d2->getBrain().setIdea(3, "Eat food");
        d2->getBrain().setIdea(4, "Guard house");
    }

    if (c1) {
        c1->getBrain().setIdea(0, "Sleep on couch");
        c1->getBrain().setIdea(1, "Chase mouse");
        c1->getBrain().setIdea(2, "Eat fish");
        c1->getBrain().setIdea(3, "Climb tree");
        c1->getBrain().setIdea(4, "Purr");
    }
    if (c2) {
        c2->getBrain().setIdea(0, "Scratch post");
        c2->getBrain().setIdea(1, "Nap");
        c2->getBrain().setIdea(2, "Steal food");
        c2->getBrain().setIdea(3, "Hide");
        c2->getBrain().setIdea(4, "Meow");
    }

    std::cout << "\n-- Dogs Ideas --\n";
    for (int i = 0; i < SIZE / 2; i++) {
        Dog* d = dynamic_cast<Dog*>(animals[i]);
        if (d) {
            std::cout << YELLOW << d->getType() << " ideas: ";
            for (int j = 0; j < 5; j++) {
                std::cout << d->getBrain().getIdea(j);
                if (j < 4) std::cout << ", ";
            }
            std::cout << RESET << std::endl;
        }
    }

    std::cout << "\n-- Cats Ideas --\n";
    for (int i = SIZE / 2; i < SIZE; i++) {
        Cat* c = dynamic_cast<Cat*>(animals[i]);
        if (c) {
            std::cout << PINK << c->getType() << " ideas: ";
            for (int j = 0; j < 5; j++) {
                std::cout << c->getBrain().getIdea(j);
                if (j < 4) std::cout << ", ";
            }
            std::cout << RESET << std::endl;
        }
    }

    
    Cat* originalCat = new Cat(*c1);
    originalCat->getBrain().setIdea(0, "New Cat Idea");

    Dog* originalDog = new Dog(*d1);
    originalDog->getBrain().setIdea(0, "New Dog Idea");

    std::cout << "\n-- After Deep Copy Modifications --\n";
    std::cout << PINK << "Original Cat idea 0: " << c1->getBrain().getIdea(0) 
              << ", Copied Cat idea 0: " << originalCat->getBrain().getIdea(0) << RESET << std::endl;
    std::cout << YELLOW << "Original Dog idea 0: " << d1->getBrain().getIdea(0) 
              << ", Copied Dog idea 0: " << originalDog->getBrain().getIdea(0) << RESET << std::endl;

    
    delete originalCat;
    delete originalDog;
    for (int i = 0; i < SIZE; i++) {
        delete animals[i];
    }

    return 0;
}