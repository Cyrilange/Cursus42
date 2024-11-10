#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>

typedef struct s_stack_node {
	int					value;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

char 	**ft_split(char *args, char space);
bool	ft_is_digit(int	n);
bool	is_valid_integer(char	*str);
bool	is_duplicate(t_stack_node *head);
bool	check_no_error(t_stack_node *head, char	**args);
void	ft_putstr(const char *str);
int	ft_atoi(const char *str);



#endif 