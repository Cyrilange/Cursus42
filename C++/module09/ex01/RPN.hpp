/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:31:24 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/17 18:12:41 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <exception>


#define ERROR_ARG "Invalid number of arguments."
#define ERROR_EXP "Invalid expression."
#define ERROR_MSG "Error:"
#define ERR_ZERO " division by zero"

class RPN {
	private:
	
	std::vector<int> _number;
	
	bool isOperator(const std::string &op) const;
	bool ft_isDigit(const std::string &op) const;
	int calculate(int a, int b, const std::string &op) const;
	
	public:
	
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& copy);
	int solve(const std::string& op);
	~RPN();
	
};