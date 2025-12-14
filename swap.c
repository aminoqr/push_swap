/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:38:24 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/14 18:39:03 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **stack)
{
	t_stack *temp;

	if(!*stack || !(*stack) -> next)
		return 0;
	temp = *stack;
	*stack = (*stack) -> next;
	(*stack) -> prev = NULL;
	temp -> next = (*stack) -> next;
	(*stack) -> next = temp;
	temp -> prev = *stack;
	if (temp->next)
		temp->next->prev = temp;
	return 1;
}

int sa(t_stack **stack_a)
{
	if(!ft_swap(stack_a))
		return 0;
	printf("sa\n");
	return 1;
}

int sb(t_stack **stack_b)
{
	if(!ft_swap(stack_b))
		return 0;
	printf("sb\n");
	return 1;
}
int ss(t_stack **stack_a, t_stack **stack_b)
{
	int result_a;
	int result_b;

	result_a = ft_swap(stack_a);
	result_b = ft_swap(stack_b);
	if(!result_a && !result_b)
		return 0;
	printf("ss\n");
	return 1;
}
