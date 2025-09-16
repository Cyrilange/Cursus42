#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    public:
        Fixed(); //default constructor
    public:
        int getValue() const; //getter
    public:
        void setValue(int v); //setter
    public:
        static int getBits(); //getter
    public:
        Fixed(const float f); //constructor perso
    public:
        Fixed(const int n); //constructor perso
    public:
        Fixed(const Fixed &other); //copy constructor
    public:
        Fixed& operator=(const Fixed& other); //operator copy = < > >= <= !=
    public:
        Fixed& operator<(const Fixed& other);
    public:
        Fixed& operator>(const Fixed& other);
    public:
        Fixed& operator!=(const Fixed& other);
    public:
        Fixed& operator>=(const Fixed& other);
    public:
        Fixed& operator<=(const Fixed& other);

    ~Fixed(); //destructor
    private:
        int value; //value
        static const int bits = 8; // bits for float fixed point

}

#endif 