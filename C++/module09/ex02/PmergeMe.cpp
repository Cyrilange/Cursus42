/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:08:04 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/18 20:14:23 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//private:

void PmergeMe::makePairDeque(std::deque<int> &data, std::deque<int> &sorted) {
	sorted.clear();
	std::deque<int> small;
	std::deque<int>::iterator it = data.begin();
	while( it != data.end()) {
		std::deque<int>::iterator first = it;
		++it;
		if(it == data.end()) {
			small.push_back(*first);
			break;
		}
		std::deque<int>::iterator second = it;
		++it;

        if (*first > *second) {
            sorted.push_back(*first);
            small.push_back(*second);
        } else {
            sorted.push_back(*second);
            small.push_back(*first);
        }
	}
	dataDeque = small;
}

void PmergeMe::makePairList(std::list<int> &data, std::list<int> &sorted) {
	sorted.clear();
	std::list<int> small;
	std::list<int>::iterator it = data.begin();
	while( it != data.end()) {
		std::list<int>::iterator first = it;
		++it;
		if(it == data.end()) {
			small.push_back(*first);
			break;
		}
		std::list<int>::iterator second = it;
		++it;

        if (*first > *second) {
            sorted.push_back(*first);
            small.push_back(*second);
        } else {
            sorted.push_back(*second);
            small.push_back(*first);
        }
	}
	dataList = small;
}



void PmergeMe::sortBigElementsDeque() {
    for (std::deque<int>::iterator it = dataDeque.begin(); it != dataDeque.end(); ++it) {
        int n = *it;
        std::deque<int>::iterator pos = std::lower_bound(sortedDeque.begin(), sortedDeque.end(), n);
        sortedDeque.insert(pos, n);
    }
    dataDeque.clear();
}


void PmergeMe::sortBigElementsList() {
    for (std::list<int>::iterator it = dataList.begin(); it != dataList.end(); ++it) {
        int n = *it;
        std::list<int>::iterator pos = sortedList.begin();
        while (pos != sortedList.end() && *pos < n) {
            ++pos;
        }
        sortedList.insert(pos, n);
    }
    dataList.clear();
}


void PmergeMe::insertSmallDeque() {
    for (std::deque<int>::iterator it = dataDeque.begin(); it != dataDeque.end(); ++it) {
        int n = *it;
        std::deque<int>::iterator pos = std::lower_bound(sortedDeque.begin(), sortedDeque.end(), n);
        sortedDeque.insert(pos, n);
    }
    dataDeque.clear();
}


void PmergeMe::insertSmallList() {
    for (std::list<int>::iterator it = dataList.begin(); it != dataList.end(); ++it) {
        int n = *it;
        std::list<int>::iterator pos = sortedList.begin();
        while (pos != sortedList.end() && *pos < n) {
            ++pos;
        }
        sortedList.insert(pos, n);
    }
    dataList.clear();
}



//public:
PmergeMe::PmergeMe(char **argv) {
	for (int i = 1; argv[i]; i++) {
		std::string s(argv[i]);
		if (s.empty())
    		throw std::runtime_error(ERR_EMPTY);
		for(size_t j = 0; j < s.size(); j++) {
			if(!std::isdigit(s[j]))
				throw std::runtime_error(ERR_DIGIT);
		}
		long value = std::atol(s.c_str());
		if (value <= 0 || value > INT_MAX)
    		throw std::runtime_error(ERR_INT);
		dataList.push_back(static_cast<int>(value));
		dataDeque.push_back(static_cast<int>(value));
	}
	if (dataList.size() < 2 || dataDeque.size() < 2)
    	throw std::runtime_error(ERR_NUM);

}

PmergeMe::PmergeMe(const PmergeMe& copy) : dataList(copy.dataList), sortedList(copy.sortedList),
dataDeque(copy.dataDeque), sortedDeque(copy.sortedDeque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
    if (this != &copy)
    {
        dataList = copy.dataList;
        sortedList = copy.sortedList;
		dataDeque = copy.dataDeque;
		sortedDeque = copy.sortedDeque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

std::deque<int> PmergeMe::algoWithDeque() {
    // separate big and small
    makePairDeque(dataDeque, sortedDeque);

    // sorting big elements
    sortBigElementsDeque();

    // insert the small ones
    insertSmallDeque();

    // return the  result
    return sortedDeque;
}


std::list<int> PmergeMe::algoWithList() {
	    // separate big and small
	makePairList(dataList, sortedList);

		// sorting big elements
	sortBigElementsList();
	
		// insert the small ones
	insertSmallList();
	
		// return the  result
	return sortedList;
}