/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-20 14:20:50 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-20 14:20:50 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0){
    std::cout << "Default constructor called" << std::endl;
};

int Fixed::getFixed_int() { 
    return Fixed::fixed_int;
}

void Fixed::setvalue(int  v) {
    this->value = v;
};
int  Fixed::getValue(){
    return this->value;
};

Fixed::Fixed(const int n) : value(n * (1 << fixed_int)) {
    std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float f) {
    this->value =  roundf(f * (1 << fixed_int));
    std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) : value(other.value)  {
   std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->value = other.value;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
    
};

int Fixed::toInt(void) const {
    return this->value >> Fixed::fixed_int;
};

float Fixed::toFloat(void) const {
    return this->value / (float)(1 << fixed_int);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
    out << obj.toFloat();
    return out;
}

Fixed::~Fixed() {
std::cout << "Destructor called" << std::endl;
};