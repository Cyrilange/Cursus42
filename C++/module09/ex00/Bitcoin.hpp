/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitcoin.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:23 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/17 00:14:35 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>
#include <exception>
#include <iostream>
#include <fstream>
#include <cstdlib>
//lower_bound()  upper_bound() std::map<std::string, float>

#define ERR_POSITIVE "Error: not a positive number.\n"
#define ERR_INPUT "Error: bad input => "
#define ERR_INT "Error: too large a number.\n"
#define ERR_FILE "Error: could not open file."
#define ERR_DAY_MONTH "Day out of range for month: "
#define ERR_MONTH "Month out of range: "
#define ERR_DAY "Day invalid: "
#define ERR_MONTH_INV "Month invalid: "
#define ERR_YEAR "Year invalid: "
#define ERR_DATE "Date format invalid: "

class Bitcoin {
private:
    std::map<std::string, float> _data;  
public:
    Bitcoin();
    Bitcoin(const Bitcoin& other);
    Bitcoin& operator=(const Bitcoin& other);
    
    void    loadData(const std::string& filename);

    float   getValue(const std::string& date) const;
    
    class   DataNotFoundException : public std::exception {
    public:
        const char* what() const throw();
    };
    ~Bitcoin();
};