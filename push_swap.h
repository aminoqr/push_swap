/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:35:56 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/15 12:36:00 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

//main.c functions
void	print_stack(t_stack *stack);
void	ft_error(void);
int is_valid_input(char *str);

//push.c functions
int ft_push(t_stack **src, t_stack **dest);
int pa(t_stack **stack_a, t_stack **stack_b);
int pb(t_stack **stack_a, t_stack **stack_b);

//rotate.c functions
int ft_rotate(t_stack **stack);
int ra(t_stack **stack_a);
int rb(t_stack **stack_b);
int rr(t_stack **stack_a, t_stack **stack_b);

//reverse_rotate.c functions
int ft_reverse_rotate (t_stack **stack);
int rra(t_stack **stack_a);
int rrb(t_stack **stack_b);
int rrr(t_stack **stack_a, t_stack **stack_b);

//stack_utils.c functions
t_stack *ft_new_node(int value);
void ft_add_back(t_stack **stack, t_stack *new_node);
void ft_add_front(t_stack **stack, t_stack *new_node);
void ft_remove_front(t_stack **stack);
void ft_remove_back(t_stack **stack);
int ft_is_duplicate(t_stack *stack, int value);
int ft_is_sorted(t_stack *stack);


//swap.c functions
int	ft_swap(t_stack **stack);
int sa(t_stack **stack_a);
int sb(t_stack **stack_b);
int ss(t_stack **stack_a, t_stack **stack_b);

#endif