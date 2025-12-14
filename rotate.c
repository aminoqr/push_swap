/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:39:57 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/14 18:40:56 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotate(t_stack **stack)
{
	t_stack *temp;
	if (!stack || !*stack)
		return 0;
	if (!(*stack)->next)
		return 1;
	temp = *stack;
	ft_remove_front(stack);
	ft_add_back(stack, temp);
	return 1;
	
}

int ra(t_stack **stack_a)
{
	if (!ft_rotate(stack_a))
		return 0;
	printf("ra\n");
	return 1;
}

int rb(t_stack **stack_b)
{
	if (!ft_rotate(stack_b))
		return 0;
	printf("rb\n");
	return 1;
}

int rr(t_stack **stack_a, t_stack **stack_b)
{
	int result_a;
	int result_b;
	
	result_a = ft_rotate(stack_a);
	result_b = ft_rotate(stack_b);
	if(!result_a && !result_b)
		return 0;
	printf("rr\n");
	return 1;
}