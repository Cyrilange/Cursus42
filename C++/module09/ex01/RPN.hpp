/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:31:24 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/19 16:50:34 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <climits>


#define ERROR_ARG "Invalid number of arguments."
#define ERROR_EXP "Invalid expression."
#define ERROR_MSG "Error:"
#define ERR_ZERO " division by zero"

class RPN {
	private:
	
	std::vector<double> _number;
	
	bool isOperator(const std::string &op) const;
	bool ft_isDigit(const std::string &op) const;
	double calculate(double a, double b, const std::string &op) const;
	
	public:
	
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& copy);
	double solve(const std::string& op);
	~RPN();
	
};