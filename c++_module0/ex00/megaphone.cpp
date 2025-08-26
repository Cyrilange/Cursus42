/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 16:59:05 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-26 16:59:05 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

int main(int argc, char *argv[])
{

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 0; i < argc; i++) {
		for (size_t j = 0; i < argv[i][j]; j++)  {
			std::cout << static_cast<char>(toupper(argv[i][j]));
		}
		std::cout << std::endl;
		}
	}
	return 0;
}