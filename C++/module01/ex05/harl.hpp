/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:58:20 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:58:20 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

class Harl {
	private:

		enum Level {
            DEBUG,
            INFO,
            WARNING,
            ERROR,
			UNKNOWN
        };

		Level stringToLevel(const std::string& level);
		void debug( void ) {
			 std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
		};
 		void info( void ) {
			 std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
		};
 		void warning( void ){
			 std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
		};
 		void error( void ){
			 std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
		};
	public:

	Harl();
		
	    void callDebug(void);
        void callInfo(void);
        void callWarning(void);
        void callError(void);

        void complain(std::string level);

	~Harl();
};

#endif