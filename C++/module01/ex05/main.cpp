/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:58:15 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:58:15 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main(int argc, char **argv) {
    Harl h;

    if (argc == 2)
        h.complain(argv[1]);
    else {
        return -1;
    }


    return 0;
}