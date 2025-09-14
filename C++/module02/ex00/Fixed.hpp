#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {

    private:
        int value; //variable to store the fixed point
        static const int eight = 8;

    public:
        Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& copy);
        
        static int getEight() { return eight; } 
        ~Fixed();


};

#endif