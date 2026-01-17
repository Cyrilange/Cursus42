/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:29 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/17 16:21:34 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitcoin.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: usage is: ./btc filename" << std::endl;
        return 1;
    }
    try {
        Bitcoin btc;
        btc.loadDB("data.csv");
        btc.loadData(argv[1]);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
