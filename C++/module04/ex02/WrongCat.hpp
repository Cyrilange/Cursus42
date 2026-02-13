/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:55:12 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:55:12 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

#define MAUVE_BOLD_ITALIC "\033[1;3;35m"
#define VIOLET_BOLD_ITALIC "\033[1;3;95m"
#define RESET "\033[0m"



class WrongCat : public WrongAnimal {
    public:

    WrongCat();
    WrongCat(const WrongCat& other);
    virtual ~WrongCat();

    using WrongAnimal::operator=;
    void makeSound() const;
};

#endif