/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-22 17:04:38 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-22 17:04:38 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    using ClapTrap::operator=;
    using ClapTrap::attack;
    void highFivesGuys(void);
    ~FragTrap();
};

#endif