/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-20 14:21:07 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-20 14:21:07 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : value(0) {}

// Construct from integer
Fixed::Fixed(const int n) {
    value = n << bits;
}

// Construct from float
Fixed::Fixed(const float f) {
    value = roundf(f * (1 << bits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    *this = other;
}

// Destructor
Fixed::~Fixed() {}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

// Get raw fixed-point value
int Fixed::getRawBits() const {
    return this->value;
}

// Set raw fixed-point value
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// Convert to float
float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << bits);
}

// Convert to int
int Fixed::toInt() const {
    return value >> bits;
}

// Comparison operators
bool Fixed::operator==(const Fixed& other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->value != other.value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->value < other.value;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->value > other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->value <= other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->value >= other.value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Pre-increment
Fixed& Fixed::operator++() {
    ++value;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

// Pre-decrement
Fixed& Fixed::operator--() {
    --value;
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Min / Max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b ? a : b);
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
