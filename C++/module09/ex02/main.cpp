/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:23:36 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/18 20:40:32 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: At least 2 numbers are required" << std::endl;
        return 1;
    }

    try {
        PmergeMe pm(argv);

        std::cout << "Before: ";
        for (int i = 1; argv[i]; ++i)
            std::cout << argv[i] << " ";
        std::cout << std::endl;

        clock_t startDeque = clock();
        std::deque<int> sortedDeque = pm.algoWithDeque();
        clock_t endDeque = clock();

        clock_t startList = clock();
        std::list<int> sortedList = pm.algoWithList();
        clock_t endList = clock();

        std::cout << "After: ";
        for (std::list<int>::iterator it = sortedList.begin(); it != sortedList.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        double durationDeque = ((double)endDeque - (double)startDeque) * MICRO_SEC / CLOCKS_PER_SEC;
        double durationList = ((double)endList - (double)startList) * MICRO_SEC / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << sortedDeque.size()
                  << " elements with std::deque : " << durationDeque << " us" << std::endl;

        std::cout << "Time to process a range of " << sortedList.size()
                  << " elements with std::list : " << durationList << " us" << std::endl;

    } catch (std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}