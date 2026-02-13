/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:53:46 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:53:46 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

#define VIOLET_BOLD_ITALIC "\033[1;3;95m"
#define RESET "\033[0m"

class WrongAnimal {
    public :

    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal(const std::string& type);
    WrongAnimal& operator=(const WrongAnimal& other);
    const std::string& getType() const;
    void setType(const std::string& type);
    virtual void makeSound() const ;
    virtual ~WrongAnimal();
    protected:
        std::string type;
    
};

#endif