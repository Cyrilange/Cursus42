#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);
        void setvalue(int v);
        int getValue();
        static int getFixed_int();
        float toFloat( void ) const; // that converts the fixed-point value to a floating-point value.
        int toInt( void ) const; //that converts the fixed-point value to an integer value.


        /*An overload of the insertion («) operator that inserts a 
        floating-point representation
        of the fixed-point number into the output stream object passed as a parameter.*/
        
        ~Fixed();
    private:
        int value;
        static const int   fixed_int   = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif