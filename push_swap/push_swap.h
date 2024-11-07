#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>

typedef struct s_stack_node {

	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

char 	**ft_split(char *args, char space);

#endif 