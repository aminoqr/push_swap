/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:35:56 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/24 18:53:24 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int					value;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack		*next;
	struct s_stack		*prev;
	struct s_stack		*target_node;
}	t_stack;

//main.c functions
void	ft_error(void);
int		is_valid_input(char *str);
int		stack_size(t_stack **stack);

//sort_utils.c functions
void	free_split(char **args);
void	fill_stack_a(t_stack **a, char **args);
void	sort_three(t_stack **stack);

//push.c functions
int		ft_push(t_stack **src, t_stack **dest);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

//rotate.c functions
int		ft_rotate(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

//reverse_rotate.c functions
int		ft_reverse_rotate(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

//stack_utils.c functions
t_stack	*ft_new_node(int value);
void	ft_add_back(t_stack **stack, t_stack *new_node);
void	ft_add_front(t_stack **stack, t_stack *new_node);
void	ft_remove_front(t_stack **stack);
void	ft_remove_back(t_stack **stack);
int		ft_is_duplicate(t_stack *stack, int value);
int		ft_is_sorted(t_stack *stack);
t_stack	*ft_find_max(t_stack **stack);
t_stack	*ft_find_min(t_stack *stack);
void	set_current_position(t_stack *stack);

//swap.c functions
int		ft_swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);

//turk_algo.c functions
t_stack	*get_target_node(t_stack *a, int b_val);
void	set_target_b(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
t_stack	*get_cheapest_node(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	move_b_to_a(t_stack **a, t_stack **b);
void	turk_sort(t_stack **a, t_stack **b);
#endif