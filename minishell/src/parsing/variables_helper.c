/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:48:14 by mariogo2          #+#    #+#             */
/*   Updated: 2025/08/08 22:30:58 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*is_var_name(const char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i] && is_var_char(str[i]))
		i++;
	*len = i;
	if (i == 0 || (i == 1 && str[0] == '_'))
	{
		return (NULL);
	}
	return (ft_strndup(str, i));
}

char	*append_str(char *base, const char *add)
{
	char	*new_str;

	if (!base)
		return (ft_strdup(add));
	new_str = malloc(ft_strlen(base) + ft_strlen(add) + 1);
	if (!new_str)
	{
		free(base);
		return (NULL);
	}
	ft_strcpy(new_str, base);
	ft_strcat(new_str, add);
	free(base);
	return (new_str);
}
