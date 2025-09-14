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

Harl::Level Harl::stringToLevel(const std::string& level) {
	  Level levelCode = UNKNOWN;
    if (level == "debug") {
        return DEBUG;
    } else if (level == "info") {
        return INFO;
    } else if (level == "warning") {
        return WARNING;
    } else if (level == "error") {
        return ERROR;
    } 
	return levelCode;
}


void Harl::complain(std::string level) {
    Level levelCode = stringToLevel(level);

    switch (levelCode) {
        case DEBUG:
            callDebug();
            break;
        case INFO:
            callInfo();
            break;
        case WARNING:
            callWarning();
            break;
        case ERROR:          
            callError();
            break;
		default:
			std::cout << "unknow level" << std::endl;
			break;
    }
}


Harl::~Harl() {}
