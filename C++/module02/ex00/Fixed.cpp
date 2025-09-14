#include "Fixed.hpp"

Fixed::Fixed() :value(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& copy) :value(copy.value) {
    std::cout << "Copy constructor called" <<std::endl;
};

Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &copy) {
        this->value = copy.value;
    }
    return *this;
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};