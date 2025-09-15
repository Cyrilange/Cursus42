#include "Fixed.hpp"

Fixed::Fixed() :value(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& copy) :value(copy.value) {
    std::cout << "Copy constructor called" <<std::endl;
};

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
};

Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &copy) {
        this->value = copy.value;
    }
    return *this;
};

void Fixed::setRawBits( int const raw ) {
 this->value = raw;
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};