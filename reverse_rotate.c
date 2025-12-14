/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:41:04 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/14 18:41:21 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_reverse_rotate (t_stack **stack)
{
	t_stack *temp;
	if (!stack || !*stack)
		return 0;
	if (!(*stack)->next)
		return 1;
	temp = *stack;
	while(temp->next)
		temp = temp->next;
	ft_remove_back(stack);
	ft_add_front(stack, temp);
	return 1;	
}

int rra(t_stack **stack_a)
{
	if(!ft_reverse_rotate(stack_a))
		return 0;
	printf("rra\n");
	return 1;
}

int rrb(t_stack **stack_b)
{
	if(!ft_reverse_rotate(stack_b))
		return 0;
	printf("rrb\n");
	return 1;
}

int rrr(t_stack **stack_a, t_stack **stack_b)
{
	int result_a;
	int result_b;
	
	result_a = ft_reverse_rotate(stack_a);
	result_b = ft_reverse_rotate(stack_b);
	if(!result_a && !result_b)
		return 0;
	printf("rrr\n");
	return 1;
}