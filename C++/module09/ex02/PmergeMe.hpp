/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:50:18 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/19 23:45:08 by csalamit         ###   ########.fr       */
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

	
	public:
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);
	~PmergeMe();

	std::deque<int> algoWithDeque() ;
	std::list<int> algoWithList()  ;

};

/*.Before: 4 3 8 98 12 123 2345
# Initial state: the list is unsorted.

Step 1: Make pairs
Big: 4 98 123
Small: 3 8 12 2345
# Step 1: creating pairs.
# For each pair of numbers, the larger goes into 'Big', the smaller into 'Small'.
# Here: (4,3) → Big=4, Small=3 ; (8,98) → Big=98, Small=8 ; (12,123) → Big=123, Small=12
# The last element 2345 has no pair → it goes into Small.

Step 1: Make pairs
Big: 98
Small: 4 123
# Recursion on 'Big': repeat the same pairing on the initial Big (4,98,123)
# New pair: (4,98) → Big=98, Small=4 ; 123 remains alone → Small=123

Step 2: After sorting big recursively
98
# Step 2: recursive sorting of Big
# Here Big=98 is already sorted because it contains only one element.

Step 3: Insert first small (4)
4 98
# Step 3: insert the first element from Small (4)
# It is placed in the correct position in the sorted Big.

Step 4: Insert small[1] = 123
4 98 123
# Step 4: insert the next element from Small (123)
# It is inserted in its correct position.

Step 2: After sorting big recursively
4 98 123
# Return from the previous recursion: Big=4 98 123 is now sorted.

Step 3: Insert first small (3)
3 4 98 123
# Insert the first element from the current Small (3)
# 3 is placed at the beginning because it is smaller than all existing elements.

Step 4: Insert small[1] = 8
3 4 8 98 123
# Insert the next Small element (8)
# 8 is placed between 4 and 98 to maintain sorted order.

Step 4: Insert small[2] = 12
3 4 8 12 98 123
# Insert Small element 12 between 8 and 98

Step 4: Insert small[3] = 2345
3 4 8 12 98 123 2345
# Insert the last Small element (2345) at the end because it is the largest.

after : 3 4 8 12 98 123 2345
# Final result: the list is fully sorted
# Each step is now clearly visible for review.
*/

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