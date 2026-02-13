/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_part_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:16:34 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/29 20:44:08 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "./get_next_line/get_next_line_bonus.h"

void	free_gnl_static(void)
{
	get_next_line(-1);
}

void	handle_line_error(t_game *game, const char *message)
{
	free_gnl_static();
	g_error_function(game, message);
}

void	g_error_function(t_game *game, const char *message)
{
	if (game)
		free_game(game);
	free_gnl_static();
	printf(RED "%s \n" RESET, message);
	exit(EXIT_FAILURE);
}

void	*check_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_function("Error\n Memory allocation failed.");
	return (ptr);
}

void	error_function(const char *message)
{
	printf(RED "%s \n" RESET, message);
	exit(EXIT_FAILURE);
}
