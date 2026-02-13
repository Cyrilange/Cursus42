/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:04:04 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:25:23 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data d;
    d.x = 42;
    d.name = "Cyril";

	Data y;
	y.name = "Jhon";
	y.name = "18";

    uintptr_t raw = Serializer::serialize(&d);
	uintptr_t raw2 = Serializer::serialize(&y);
    Data* ptr2 = Serializer::deserialize(raw);
	Data* ptr1 = Serializer::deserialize(raw2);
	std::cout << "================== test positivemake =================" << std::endl;

    std::cout << "Original pointer: " << &d << std::endl;
    std::cout << "Deserialized pointer: " << ptr2 << std::endl;

	std::cout << "Original pointer: " << &y << std::endl;
    std::cout << "Deserialized pointer: " << ptr1 << std::endl;

    if (ptr2 == &d) {std::cout << "Success! Pointers match." << std::endl;}
    else {std::cout << "Error! Pointers do not match." << std::endl; }

	if (ptr1 == &y)
        std::cout << "Success! Pointers match." << std::endl;
    else {std::cout << "Error! Pointers do not match." << std::endl;}
	std::cout << "================== test negative =================" << std::endl;
	std::cout << "Original pointer: " << &d << std::endl;
    std::cout << "Deserialized pointer: " << ptr1 << std::endl;
	if (ptr1 == &d)
		std::cout << "Success! Pointers match." << std::endl;
	else
		std::cout << "Error! Pointers do not match." << std::endl;

    return 0;
}