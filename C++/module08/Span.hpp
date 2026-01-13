/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:04:23 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/13 23:41:12 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>
#include <exception>
#include <vector>
#include <cstdint>


class Span {
	public:
	Span(unsigned int n);
	Span(const Span& copy);
	Span& operator=(const Span& copy);
	std::vector<int>& getNumbers();
	unsigned int getMaxSize();
	class sizeIsFull : public std::exception {
		public:
		const char* what() const throw();
	};

	void addNumber(int n);
	void addMultipleNumbers(const std::vector<int>& n);
	int shortestSpan();
	int longestSpan();
	~Span();
	


	private:
	Span();
	unsigned int _maxSize;
	std::vector<int> _numbers;
};