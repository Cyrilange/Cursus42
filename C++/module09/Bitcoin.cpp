/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitcoin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:26 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/16 17:03:19 by csalamit         ###   ########.fr       */
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
}

float   Bitcoin::getValue(const std::string& date) const {
}

Bitcoin::~Bitcoin() {}