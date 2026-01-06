/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:30:03 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/06 13:44:29 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}


static Base * generate(void) {
	int random = std::rand() % 3;
	if(random == 0) {return new A;}
	if(random == 1) {return new B;}
	return new C;
}

static void identify(Base* p) {
	if(dynamic_cast<A*>(p)) {std::cout << "A" << std::endl;}
	else if(dynamic_cast<B*>(p)) {std::cout << "B" << std::endl;}
	else if(dynamic_cast<C*>(p)) {std::cout << "C" << std::endl;}
}

static void identify(Base& p) {
	//A
	try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &e) {}
	//B
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &e) {}
	//C
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &e) {}
}

int main(void) {
    std::srand(std::time(NULL));
    Base* randomOj = generate();

    std::cout << "Identify with pointer *: ";
    identify(randomOj);

    std::cout << "Identify with reference &: ";
    identify(*randomOj);

  
    delete randomOj;

    return 0;
}