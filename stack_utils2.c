/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:50:00 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/24 18:50:10 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_duplicate(t_stack *stack, int value)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*ft_find_max(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*max;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	max = *stack;
	while (temp)
	{
		if (temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*min;

	if (!stack)
		return (NULL);
	temp = stack;
	min = stack;
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	return (min);
}

void	set_current_position(t_stack *stack)
{
	int	index;
	int	size;

	if (!stack)
		return ;
	index = 0;
	size = stack_size(&stack);
	while (stack)
	{
		stack->index = index;
		if (index <= size / 2)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		index++;
		stack = stack->next;
	}
}
