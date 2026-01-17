/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:31:27 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/17 18:16:53 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


//class constructor ,copy,  operator assign and destructor
RPN::RPN() {}
RPN::RPN(const RPN& copy) : _number(copy._number) {}
RPN& RPN::operator=(const RPN& copy) {
	if(this != &copy) {
		_number = copy._number;
	}
	return *this;
}
RPN::~RPN() {}

//private methode
bool RPN::isOperator(const std::string &op) const {
	return (op == "+" || op == "-" || op == "/" || op == "*");
}
bool RPN::ft_isDigit(const std::string &op) const
{
    if (op.empty())
        return false;
    size_t start = 0;
    bool isNegative = false;
    if (op[0] == '-') {
        if (op.length() != 2)
            return false;
        start = 1;
        isNegative = true;
    } else {
        if (op.length() != 1)
            return false;
    }
    if (!std::isdigit(op[start]))
        return false;
    int value = op[start] - '0';
    if (isNegative)
        value = -value;

    return (value >= -9 && value <= 9);
}


int RPN::calculate(int a, int b, const std::string &op) const
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error(std::string(ERROR_MSG) + ERR_ZERO);
        return a / b;
    }
    throw std::runtime_error(std::string(ERROR_MSG) + " " + ERROR_EXP);
}

//public method solve 

int RPN::solve(const std::string& op) {
    std::istringstream iss(op);
    std::string token;
    
    _number.clear();
    
    while (iss >> token)
    {
        if (ft_isDigit(token) == true)
        {
            int digit = atoi(token.c_str());
            _number.push_back(digit);
        }
        else if (isOperator(token))
        {
            if (_number.size() < 2)
                throw std::runtime_error(std::string(ERROR_MSG) + " " + ERROR_EXP);
            
            int b = _number.back();
            _number.pop_back();      
            int a = _number.back();
            _number.pop_back();         
            int result = calculate(a, b, token);
            _number.push_back(result);
        }
        else
        {
            throw std::runtime_error(std::string(ERROR_MSG) + " " + ERROR_EXP);
        }
    }
    
    if (_number.size() != 1)
        throw std::runtime_error(std::string(ERROR_MSG) + " " + ERROR_EXP);
    
    return _number.back();
}