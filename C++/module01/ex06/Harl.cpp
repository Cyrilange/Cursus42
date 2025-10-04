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



Harl::Harl() {};

void Harl::debug(void) {
    std::cout << "< DEBUG >" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void) {
    std::cout << "< INFO >" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void) {
    std::cout << "< WARNING >" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error(void) {
    std::cout << "< ERROR >" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}




void Harl::callDebug(void) {
    debug();
}

void Harl::callInfo(void) {
    info();
}

void Harl::callWarning(void) {
    warning();
}

void Harl::callError(void) {
    error();
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
