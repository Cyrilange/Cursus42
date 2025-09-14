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

int main() {
    Harl harl;
    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");

    return 0;
}