/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniutils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 11:00:20 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 11:00:20 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIUTILS_H
# define MINIUTILS_H

# include "../../includes/libft/libft.h"
# include "../../includes/minishell.h"
# include <stdbool.h>

// matrix
char	**matrix_str_add(char **matrix, char *newstr);
char	**matrix_str_dup(char **matrix, int replaceline, char *newstr);
void	matrix_str_print(char **matrix);
int		matrix_len(char **matrix);
void	matrix_free(char ***matrix);

// errors
void	ft_error(char *str);

#endif
