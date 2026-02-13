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
		void debug( void );
 		void info( void );
 		void warning( void );
 		void error( void );
        
	public:

	Harl();
		
	    void callDebug(void);
        void callInfo(void);
        void callWarning(void);
        void callError(void);
        int getLevel(const std::string& level);

       

        void complain(std::string level);

	~Harl();
};

#endif