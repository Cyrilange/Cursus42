/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:57:54 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/13 00:05:18 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    v.push_back(12);
    v.push_back(32);
    v.push_back(87);
    v.push_back(90);
	std::cout << "Value are : 12 / 32 / 87 / 90" << std::endl;
    int value = 90;
	std::cout << "==========================" << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "Test for 90" << std::endl;
    try {
        easyFind(v, value);
        std::cout << "Value found" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    value = 42;
	std::cout << "==========================" << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "Test for 42" << std::endl;
    try {
        easyFind(v, value);
        std::cout << "Value found" << std::endl;
    } catch (EasyFindExeption &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "==========================" << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "Your turn, enter a value :" << std::endl;
	std::cin >> value;
	try {
        easyFind(v, value);
        std::cout << "Value found" << std::endl;
    } catch (EasyFindExeption &e) {
        std::cout << e.what() << std::endl;
    }
	
	std::cout << "==========================" << std::endl;
	std::cout << "|           END          |" << std::endl;
	std::cout << "==========================" << std::endl;
    return 0;
}
