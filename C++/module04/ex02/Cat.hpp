/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:54:32 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:54:32 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

#define BOLD_YELLOW "\033[1;33m"
#define RESET       "\033[0m"


class Cat : public Aanimal {
    public:

    Cat();
    Cat(const Cat& other);
    virtual ~Cat();

    Aanimal& operator=(const Cat& other);
    Brain& getBrain() const;
    void makeSound() const ;

    private:

    Brain* brain;
};

#endif