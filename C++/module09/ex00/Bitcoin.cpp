/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitcoin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:26 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/16 18:52:18 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitcoin.hpp"

Bitcoin::Bitcoin() {}
Bitcoin::Bitcoin(const Bitcoin& other) : _data(other._data) {}
Bitcoin& Bitcoin::operator=(const Bitcoin& other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

const char* Bitcoin::DataNotFoundException::what() const throw() {
    return "Error: Data not found for the given date.";
}

void    Bitcoin::loadData(const std::string& filename) {
    std::ifstream file(filename, std::ios::in);
    if(!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    
    while(std::getline(file, line)) {
        if(line.empty())
            continue;
        
        size_t comma = line.find(',');
        if(comma == std::string::npos)
            continue;
        
        std::string date = line.substr(0, comma);
        std::string valueStr = line.substr(comma + 1);
        
        std::stringstream ss(valueStr);
        float value;
        if(ss >> value) {
            _data[date] = value;
        } else {
            std::cerr << "Error: Invalid value for date " << date << std::endl;
        }
    }
    file.close();
}

float   Bitcoin::getValue(const std::string& date) const {
}

Bitcoin::~Bitcoin() {}