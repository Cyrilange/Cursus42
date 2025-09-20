/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-20 14:20:36 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-20 14:20:36 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int value; //variable to store the fixed point
        static const int eight = 8; //use like fixed_value = float_value * (1 << eight)

    public:
        Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& copy);
        
        
        int getRawBits( void ) const; //returns the raw value of the fixed-point value
        void setRawBits( int const raw ); //  sets the raw value of the fixed-point number.

        static int getEight() { return eight; } 
        ~Fixed();


};

#endif