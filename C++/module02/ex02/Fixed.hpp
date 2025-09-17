#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int value;                        // Raw fixed-point value
        static const int bits = 8;        // Number of fractional bits

    public:
        // Constructors
        Fixed();                          // Default constructor
        Fixed(const int n);               // Construct from integer
        Fixed(const float f);             // Construct from float
        Fixed(const Fixed& other);        // Copy constructor
        ~Fixed();                         // Destructor

        // Assignment operator
        Fixed& operator=(const Fixed& other);

        // Getters / Setters
        int getRawBits() const;           // Get raw fixed-point value
        void setRawBits(int const raw);   // Set raw fixed-point value
        float toFloat() const;            // Convert to float
        int toInt() const;                // Convert to int

        // Comparison operators
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;

        // Arithmetic operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Increment / Decrement operators
        Fixed& operator++();      // Pre-increment (++a)
        Fixed operator++(int);    // Post-increment (a++)
        Fixed& operator--();      // Pre-decrement (--a)
        Fixed operator--(int);    // Post-decrement (a--)

        // Min / Max functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Stream insertion operator (for output)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
