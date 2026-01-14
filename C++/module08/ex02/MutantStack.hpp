/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:41:05 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/14 22:37:59 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using std::cout; using std::endl;

template <typename T>
class MutantStack : public std::stack<T> {
	public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack();
	MutantStack(const MutantStack& copy);
	MutantStack& operator=(const MutantStack& copy);
	iterator begin();
	iterator end();
	~MutantStack();
	
	
};

template <typename T>
MutantStack<T>::MutantStack() {cout << "Constructor called" << endl;};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) {*this = copy; cout << "Constructor called" << endl;};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& copy) {
	cout << "copy assignment operator" << endl;
	std::stack<int>::operator=(copy);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {cout << "Destructor called" << endl;};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
};	

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
};		