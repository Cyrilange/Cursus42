/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:04:23 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/05 18:12:28 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"

class Serializer {

	public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	private:
	Serializer();
	Serializer(const Serializer& );
	Serializer &operator=(const Serializer&);
	~Serializer();
};