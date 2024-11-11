#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>

typedef struct s_stack_node {
	int					value;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

t_stack_node	*create_node(int value);
bool			ft_is_digit(int	n);
bool			is_valid_integer(char	*str);
bool			is_duplicate(t_stack_node *head);
bool			check_no_error(t_stack_node *head, char	**args);
void			ft_putstr(const char *str);
int				ft_atoi(const char *str);
bool			is_sorted(t_stack_node *head);
void			sa(t_stack_node **stack_a, int print);
void			sb(t_stack_node **stack_b, int print);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b, int print);
void			ra(t_stack_node **stack_a, int print);
void			rb(t_stack_node **stack_b, int print);
void			rra(t_stack_node **stack_a, int print);
void			rrb(t_stack_node **stack_b, int print);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b, int print);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b, int print);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b, int print);




#endif 