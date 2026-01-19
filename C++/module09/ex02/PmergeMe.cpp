/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:08:04 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/19 18:56:44 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//private:

static size_t jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t a = 0, b = 1, c;
    for (size_t i = 2; i <= n; ++i)
    {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

void PmergeMe::makePairDeque( std::deque<int> &input, std::deque<int> &big, std::deque<int> &small)
{
    big.clear();
    small.clear();

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            big.push_back(input[i]);
            small.push_back(input[i + 1]);
        }
        else
        {
            big.push_back(input[i + 1]);
            small.push_back(input[i]);
        }
    }

    if (input.size() % 2)
        small.push_back(input.back());
}


void PmergeMe::makePairList(std::list<int> &input,std::list<int> &big,std::list<int> &small)
{
    big.clear();
    small.clear();

    std::list<int>::iterator it = input.begin();

    while (it != input.end())
    {
        std::list<int>::iterator first = it;
        ++it;
        if (it == input.end())
        {
            small.push_back(*first);
            break;
        }
        std::list<int>::iterator second = it;
        ++it;
        if (*first > *second)
        {
            big.push_back(*first);
            small.push_back(*second);
        }
        else
        {
            big.push_back(*second);
            small.push_back(*first);
        }
    }
}




void PmergeMe::fordJohnsonDeque(std::deque<int> &data) {
if (data.size() <= 1)
        return;

    std::deque<int> big, small;
    makePairDeque(data, big, small);
    fordJohnsonDeque(big);
    data = big;
    if (!small.empty())
    {
        data.insert(
            std::lower_bound(data.begin(), data.end(), small[0]),
            small[0]);
    }
    size_t index = 1;
    size_t j = 1;

    while (index < small.size())
    {
        size_t next = jacobsthal(j++);
        for (; index < small.size() && index < next; ++index)
        {
            int value = small[index];
            std::deque<int>::iterator pos =
                std::lower_bound(data.begin(), data.end(), value);
            data.insert(pos, value);
        }
    }
}


void PmergeMe::fordJohnsonList(std::list<int> &data)
{
    if (data.size() <= 1)
        return;

    std::list<int> big;
    std::list<int> small;
    makePairList(data, big, small);
    fordJohnsonList(big);
    data = big;
    if (!small.empty())
    {
        int first = small.front();
        std::list<int>::iterator pos = data.begin();
        while (pos != data.end() && *pos < first)
            ++pos;
        data.insert(pos, first);
    }
    size_t index = 1;
    size_t j = 1;

    while (index < small.size())
    {
        size_t next = jacobsthal(j++);
        size_t limit = (next < small.size()) ? next : small.size();

        for (; index < limit; ++index)
        {
            std::list<int>::iterator it = small.begin();
            std::advance(it, index);// to immitate an index
            int value = *it;

            std::list<int>::iterator pos = data.begin();
            while (pos != data.end() && *pos < value)
                ++pos;

            data.insert(pos, value);
        }
    }
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
		if (value > INT_MAX)
    		throw std::runtime_error(ERR_INT);
        if (value < 0 )
            throw std::runtime_error(ERR_POS);
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
   
    fordJohnsonDeque(dataDeque);
    return dataDeque;
}


std::list<int> PmergeMe::algoWithList() {
    
    
    fordJohnsonList(dataList);
   
    return dataList;
}