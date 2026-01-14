/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:04:26 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/14 17:35:39 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n), _numbers() {}
Span::Span(const Span& copy) : _maxSize(copy._maxSize), _numbers(copy._numbers)  {}
Span& Span::operator=(const Span& copy) {
	if(this == &copy) {
		this->_maxSize = copy._maxSize;
		this->_numbers = copy._numbers;
		
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int n) {
	if(_numbers.size() >= _maxSize) {throw sizeIsFull();}
	_numbers.push_back(n);
}

int Span::shortestSpan() const{
	if(_numbers.size() < 2) {throw sizeTooSmall();}
	std::vector<int> temp = _numbers;
	std::sort(temp.begin(), temp.end());
	int firstDiff = temp[1] - temp[0];
	for(size_t i = 1; i < temp.size() - 1; i++) {
		int diff = temp[i + 1] - temp[i];
		if(diff < firstDiff) {firstDiff = diff;}
	}
	return firstDiff;
}

int Span::longestSpan() const{
	if(_numbers.size() < 2) {throw sizeTooSmall();}
	
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	//std::cout << max << " - " << min << " = "<< std::endl;
	return max - min;
}

void Span::generateNumbers(int n) {
	for (int i = 0; i < n; i++) {
		int value = std::rand();
		this->addNumber(value);
		std::cout << "index : " << i + 1 << " = " << value << std::endl;
	}
}



const char* Span::sizeIsFull::what() const throw() {
	return "Size is full";
}

const char* Span::sizeTooSmall::what() const throw() {
	return "Size too small";
}