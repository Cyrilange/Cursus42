/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-27 10:45:40 by csalamit          #+#    #+#             */
/*   Updated: 2024-04-27 10:45:40 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resultat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	resultat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (!resultat)
	{
		return (NULL);
	}
	if (!s1 || !s2)
	{
		return (NULL);
	}
	while (s1[i])
		resultat[j++] = s1[i++];
	i = 0;
	while (s2[i])
		resultat[j++] = s2[i++];
	resultat[j] = '\0';
	return (resultat);
}
