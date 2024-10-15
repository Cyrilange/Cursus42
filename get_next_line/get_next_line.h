/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-27 13:51:42 by csalamit          #+#    #+#             */
/*   Updated: 2024-06-27 13:51:42 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13214637
# endif

char		*get_next_line(int fd);
char		*ft_fill_line(char *buffer, int fd);
void		*ft_calloc(size_t count, size_t size);
char		*ft_read_line(char *line_buffer);
int			ft_strlen(const char	*str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_update(char *buffer);
char		*ft_free(char *buffer);
char		*ft_joinfree(char *buffer, char *aux);

#endif