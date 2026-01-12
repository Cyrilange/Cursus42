/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:49:05 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/13 00:06:43 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>
#include <exception>


class EasyFindExeption: public std::exception {
	public:
	const char *what() throw() {
		return "Error\nValue not found";
	}
};

template <typename T>
void easyFind(T& container, int value) {
	if(std::find(container.begin(), container.end(), value) == container.end())
		throw EasyFindExeption();
}