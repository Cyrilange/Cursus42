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

#include "Harl.hpp"



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

int Harl::getLevel(const std::string& level) {
    return static_cast<int>(stringToLevel(level));
}

Harl::Level Harl::stringToLevel(const std::string& s) {
    if (s == "DEBUG") return DEBUG;
    if (s == "INFO") return INFO;
    if (s == "WARNING") return WARNING;
    if (s == "ERROR") return ERROR;
    return UNKNOWN;
}

void Harl::complain(std::string level) {
    int lvl = getLevel(level);
    Level levelCode = static_cast<Level>(lvl); // fall trought is a comm to make the compiler understand It is my choice

    switch (levelCode) {
        case DEBUG:
            callDebug();
            // fall through 
        case INFO:
            callInfo();
            // fall through
        case WARNING:
            callWarning();
            // fall through
        case ERROR:          
            callError();
            break;
		default:
			std::cout << "unknow level" << std::endl;
			break;
    }
}



Harl::~Harl() {}
