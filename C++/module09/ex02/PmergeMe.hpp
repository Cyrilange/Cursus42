/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:50:18 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/18 20:15:13 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <climits>
#include <ctime>

#define ERR_DIGIT "only numbers accepted"
#define ERR_NUM   "At least 2 numeros needed"
#define ERR_INT   "number too big"
#define ERR_EMPTY "empty"

/*

step:
1-create group of 2 
2-take the big ones
3-insert small ones 
4-if array odd , insert the one left alone at the end via a basic binary insertion*/

class PmergeMe {
	private:
	std::list<int> dataList;
    std::list<int> sortedList;
    std::deque<int> dataDeque;
    std::deque<int> sortedDeque;


	
	void makePairDeque(std::deque<int> &data, std::deque<int> &sorted);
	void makePairList(std::list<int> &data, std::list<int> &sorted);
	
	void sortBigElementsDeque();
	void sortBigElementsList();


	void insertSmallDeque();
	void insertSmallList();
	
	public:
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);
	~PmergeMe();

	std::deque<int> algoWithDeque();
	std::list<int> algoWithList();

};