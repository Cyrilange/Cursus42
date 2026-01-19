/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:50:18 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/19 18:12:13 by csalamit         ###   ########.fr       */
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
#define ERR_POS   "only positive numbers accepted"

#define MICRO_SEC 1000000.0

class PmergeMe {
	private:
	std::list<int> dataList;
    std::list<int> sortedList;
    std::deque<int> dataDeque;
    std::deque<int> sortedDeque;


	
	void makePairDeque(    std::deque<int> &input, std::deque<int> &big, std::deque<int> &small);
	void makePairList(std::list<int> &input, std::list<int> &big, std::list<int> &small);
	
	void fordJohnsonDeque(std::deque<int> &data);
	void fordJohnsonList(std::list<int> &data);


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

/*Ford–Johnson Algorithm — Step by Step
1. Input validation

	The algorithm starts with a sequence of positive integers.
	If the sequence contains fewer than two elements, it is already sorted.

2. Pairing the elements

	The sequence is split into pairs of two elements:

	For each pair, the larger element is called the “big” element

	The smaller element is called the “small” element

	If the number of elements is odd, the last element is stored as a small element.

	This step reduces the problem size by half.

3. Recursive sort of big elements

	All big elements are placed into a new sequence.

	This sequence is then sorted recursively using the same Ford–Johnson algorithm.

	At this point, the sequence of big elements is fully sorted.

4. Initial insertion

	The first small element is inserted into the sorted big sequence using
	binary search (or linear search for a list).

	This creates a partially sorted sequence.

5. Jacobsthal sequence computation

	To minimize the number of comparisons, the algorithm uses the
	Jacobsthal sequence:

	J(0) = 0
	J(1) = 1
	J(n) = J(n−1) + 2 × J(n−2)


	The Jacobsthal numbers determine the order in which small elements are inserted.

6. Insertion of small elements

	The remaining small elements are inserted into the sorted sequence:

	They are not inserted in natural order

	They are inserted following the Jacobsthal index order

	Each insertion uses a binary search (or bounded linear search)

	This step minimizes the total number of comparisons.

7. Final sorted sequence

	After all small elements are inserted, the sequence is fully sorted.

	The result has the same elements as the input, in ascending order.*/