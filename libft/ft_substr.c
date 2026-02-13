/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-21 14:56:58 by csalamit          #+#    #+#             */
/*   Updated: 2024-04-21 14:56:58 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * (1));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) <= start || ft_strlen(s) == 0)
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
/*

int main() {
    const char *original = "Bonjour, monde!";
    unsigned int start = 1;
    size_t len = 9; 

    
    char *substring = ft_substr(original, start, len);

    if (substring != NULL) {
        printf("substring : %s\n", substring);
     
        free(substring);
    } else {
        printf("error doc.\n");
    }

    return 0;
}*/