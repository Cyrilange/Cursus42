/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:52:06 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/08 19:53:44 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {
	std::cout << "Default constructor called" << std::endl;
} 

template <typename T>
Array<T>::Array(Array const& copy) : _data(new T[copy._size]()), _size(copy._size) {
	for(unsigned int i = 0; i < _size; i++) {
		_data[i] = copy._data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& copy) {
	if (this == &copy)
		return *this;
	delete[] _data;
	_size = copy._size;
	_data = new T[_size]();
	for(unsigned int i = 0; i < _size; i++) {
		_data[i] = copy._data[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _data[index];
}

template <typename T>
unsigned int Array<T>::getSize() const {
    return _size;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}
