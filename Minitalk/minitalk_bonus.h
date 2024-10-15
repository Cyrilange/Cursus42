/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-14 09:48:39 by csalamit          #+#    #+#             */
/*   Updated: 2024-10-14 09:48:39 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h> 
# include <sys/types.h>
# include "libft/libft.h"
# include "Printf/ft_printf.h"

void	send_signal(int pid, char str);
void	handle_signal(int signal);
int		ft_atoi(const char *str);
void	signal_back(int signal);

#endif