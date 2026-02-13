/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 12:07:54 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 12:07:54 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	signal_reset_prompt(int signo)
{
	(void)signo;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_status = 130;
}

void	noninteractive_sigint(int signal)
{
	(void)signal;
	rl_on_new_line();
}

void	noninteractive_sigquit(int signal)
{
	(void)signal;
	printf("Quit (core dumped)\n");
	rl_on_new_line();
}

void	set_signals_noninteractive(void)
{
	signal(SIGINT, noninteractive_sigint);
	signal(SIGQUIT, noninteractive_sigquit);
}

void	set_signals_interactive(void)
{
	signal(SIGINT, signal_reset_prompt);
	signal(SIGQUIT, SIG_IGN);
}
