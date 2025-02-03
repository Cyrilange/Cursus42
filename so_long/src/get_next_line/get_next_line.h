#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "../../includes/libft/libft.h"

# ifndef MAX_FD
#  define MAX_FD 1024
# endif


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

void	*ft_calloc(size_t count, size_t size);

int		ft_strlen2(const char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char *s1, const char *s2);

char	*ft_free(char *buffer);

#endif