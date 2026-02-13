/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 12:06:48 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 12:06:48 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniutils.h"
#include <stdio.h>

static int	ft_strdup_into(char **dst, const char *src);

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL)
		return (0);
	while (matrix[i] != NULL)
		i++;
	return (i);
}

void	matrix_free(char ***matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[0] && matrix[0][i])
	{
		free(matrix[0][i]);
		i++;
	}
	if (matrix)
	{
		free(matrix[0]);
		*matrix = NULL;
	}
}

static char	**dup_with_replacement(char **matrix, int replaceline, char *newstr)
{
	char	**newmatrix;
	int		len_matrix;
	int		i[2];

	i[0] = -1;
	i[1] = 0;
	len_matrix = matrix_len(matrix);
	newmatrix = malloc(sizeof(char *) * (len_matrix + 1));
	if (!newmatrix)
		return (NULL);
	while (matrix[++i[0]] != NULL)
	{
		if (i[0] == replaceline && newstr == NULL)
			continue ;
		if (i[0] == replaceline)
		{
			if (ft_strdup_into(&newmatrix[i[1]], newstr) == 0)
				return (matrix_free(&newmatrix), NULL);
		}
		else if (ft_strdup_into(&newmatrix[i[1]], matrix[i[0]]) == 0)
			return (matrix_free(&newmatrix), NULL);
		i[1]++;
	}
	newmatrix[i[1]] = NULL;
	return (newmatrix);
}

static int	ft_strdup_into(char **dst, const char *src)
{
	*dst = ft_strdup(src);
	return (*dst != NULL);
}

char	**matrix_str_dup(char **matrix, int replaceline, char *newstr)
{
	return (dup_with_replacement(matrix, replaceline, newstr));
}
