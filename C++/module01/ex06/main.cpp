/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-20 14:20:14 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-20 14:20:14 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "must use with an arg" << std::endl;
        return -1;
    }
    Harl harl;
    std::string input = argv[1];

    if (input == "DEBUG" || input == "INFO" || input == "WARNING" || input == "ERROR") {
        
        harl.complain(input);
    }
    else if (input == "I do not like this")
        std::cout << "INFO" << std::endl;

    return 0;
}