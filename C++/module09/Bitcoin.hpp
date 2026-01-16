/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitcoin.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:23 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/16 16:58:59 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>
#include <exception>
#include <iostream>
#include <fstream>
//lower_bound()  upper_bound() std::map<std::string, float>

class Bitcoin {
private:
    std::map<std::string, float> _data; // date, value  
public:
    Bitcoin();
    Bitcoin(const Bitcoin& other);
    Bitcoin& operator=(const Bitcoin& other);
    
    void    loadData(const std::string& filename);
    float   getValue(const std::string& date) const;
    class   DataNotFoundException : public std::exception {
    public:
        const char* what() const throw() {
            //return "Data not found for the given date.";
        }
    };
    ~Bitcoin();
};