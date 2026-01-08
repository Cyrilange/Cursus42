/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:57:43 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/08 17:02:33 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

# define RESET          "\033[0m"
# define BRED       "\033[1;31m"
# define BYELLOW    "\033[1;33m"
# define BCYAN      "\033[1;36m"

template <typename T>
void	iter(T *arr, size_t len,void (*func)(T&)) {
	for(size_t i = 0; i < len; i++) {
		func(arr[i]);
	}
}

template <typename T>
void	iter(const T *arr, size_t len,void (*func)(const T&)) {
	for(size_t i = 0; i < len; i++) {
		func(arr[i]);
	}
}

//functions to taste iter 

template <typename T>
void increment(T& i) {
	i+= 2;
}

template <typename T>
void decrement(T& i) {
	i--;
}

template <typename T>
void print(T& s) {
	std::cout << s << std::endl;
} 