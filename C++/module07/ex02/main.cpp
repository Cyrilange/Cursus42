/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:46:00 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/08 20:11:39 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main() {
    std::cout << "========== Array<int> ==========\n";
    Array<int> intArr(5);
    for (unsigned int i = 0; i < intArr.getSize(); ++i)
        intArr[i] = i * 10;


    for (unsigned int i = 0; i < intArr.getSize (); ++i)
        std::cout << intArr[i] << " ";
    std::cout << "\n\n";

    std::cout << "========== Array<float> ==========\n";
    Array<float> floatArr(5);
    for (unsigned int i = 0; i < floatArr.getSize(); ++i)
        floatArr[i] = i + 0.5f;

    for (unsigned int i = 0; i < floatArr.getSize(); ++i)
        std::cout << floatArr[i] << " ";
    std::cout << "\n\n";

    std::cout << "========== Array<double> ==========\n";
    Array<double> doubleArr(3);
    doubleArr[0] = 3.14;
    doubleArr[1] = 2.718;
    doubleArr[2] = 1.618;

    for (unsigned int i = 0; i < doubleArr.getSize(); ++i)
        std::cout << doubleArr[i] << " ";
    std::cout << "\n\n";

    std::cout << "========== Array<char> ==========\n";
    Array<char> charArr(5);
    for (unsigned int i = 0; i < charArr.getSize(); ++i)
        charArr[i] = 'A' + i;

    for (unsigned int i = 0; i < charArr.getSize(); ++i)
        std::cout << charArr[i] << " ";
    std::cout << "\n\n";

    std::cout << "========== Array<std::string> ==========\n";
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "42";

    for (unsigned int i = 0; i < strArr.getSize(); ++i)
        std::cout << strArr[i] << " ";
    std::cout << "\n\n";

    std::cout << "========== Copy Test ==========\n";
    Array<int> intCopy(intArr);
    intCopy[0] = 999;

    std::cout << "Original intArr[0]: " << intArr[0] << "\n";
    std::cout << "Copied intCopy[0]: " << intCopy[0] << "\n";
    try {
        std::cout << intArr[10];
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}