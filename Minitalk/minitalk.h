/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 15:55:24 by csalamit          #+#    #+#             */
/*   Updated: 2024-10-12 15:55:24 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h> 
# include <sys/types.h>
# include "libft/libft.h"
# include "Printf/ft_printf.h"

void	send_signal(int pid, char str);
void	handle_signal(int signal);
int		ft_atoi(const char *str);

#endif