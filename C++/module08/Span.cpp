/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:04:26 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/13 23:46:54 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"



void Span::addNumber(int n) {
	if(_numbers.size() >= _maxSize) {throw sizeIsFull();}
	_numbers.push_back(n);
}

const char* Span::sizeIsFull::what() const throw() {
	return "Size is full";
}