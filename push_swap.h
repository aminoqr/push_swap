/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:35:56 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/14 16:20:01 by aasylbye         ###   ########.fr       */
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

void ft_add_back(t_stack **stack, t_stack *new_node);
void ft_add_front(t_stack **stack, t_stack *new_node);
t_stack *ft_new_node(int value);
int ft_is_duplicate(t_stack *stack, int value);
void ft_remove_front(t_stack **stack);


#endif