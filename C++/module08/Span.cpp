/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:04:26 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/13 23:41:36 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

std::vector<int>& Span::getNumbers()
{
    return this->_numbers;
}

unsigned int Span::getMaxSize() {
	return this->_maxSize;
}


void Span::addNumber(int n) {
	if(getNumbers().size() > getMaxSize()) {throw sizeIsFull();}
	getNumbers().push_back(n);
}

const char* Span::sizeIsFull::what() const throw() {
	return "Size is full";
}