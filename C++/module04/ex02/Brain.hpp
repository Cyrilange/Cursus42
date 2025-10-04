/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:54:24 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:54:24 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <iostream>
#include <string>

class Brain {
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        const std::string& getIdea(unsigned int i) const;
        void setIdea(unsigned int i, std::string idea);
        ~Brain();
    private:
        std::string ideas[100];
};

#endif