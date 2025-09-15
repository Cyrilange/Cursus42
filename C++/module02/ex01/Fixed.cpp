#include "Fixed.hpp"

Fixed::Fixed() : value(0){
    
};


int Fixed::getFixed_int() { 
    return Fixed::fixed_int;
}

Fixed::Fixed(const int n) : value(n * (1 << fixed_int)) {

};

Fixed::Fixed(const float f) {
    int fixed_point = roundf(f * (1 << fixed_int));
};

Fixed::Fixed(const Fixed &other) : value(other.value)  {
   
};

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
};


Fixed::~Fixed() {};