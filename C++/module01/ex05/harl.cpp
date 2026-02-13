/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:58:24 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:58:24 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

#include "harl.hpp"


Harl::Harl() {}


void Harl::callDebug(void) {
    void (Harl::*ptr)() = &Harl::debug;
    (this->*ptr)();
}

void Harl::callInfo(void) {
    void (Harl::*ptr)() = &Harl::info;
    (this->*ptr)();  
}

void Harl::callWarning(void) {
    void (Harl::*ptr)() = &Harl::warning;
    (this->*ptr)();
}

void Harl::callError(void) {
    void (Harl::*ptr)() = &Harl::error;
    (this->*ptr)(); 
}

void Harl::complain(std::string level) {
   
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[])() = {
        &Harl::callDebug,
        &Harl::callInfo,
        &Harl::callWarning,
        &Harl::callError
    };

  
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return;
        }
    }

    std::cout << "Unknown level" << std::endl;
}



Harl::~Harl() {}
