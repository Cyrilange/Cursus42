/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:04:23 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/14 23:35:35 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <exception>
#include <vector>

#include <limits>
#include <ctime>




class Span {
	public:
	Span(unsigned int n);
	Span(const Span& copy);
	Span& operator=(const Span& copy);

	class sizeIsFull : public std::exception {
		public:
		const char* what() const throw();
	};

	class sizeTooSmall : public std::exception {
		public: 
		const char* what() const throw();
	};

	void addNumber(int n);
	void generateNumbers(int n);
	int shortestSpan() const;
	int longestSpan() const;
	~Span();
	


	private:
	Span();
	unsigned int _maxSize;
	std::vector<int> _numbers;
};

