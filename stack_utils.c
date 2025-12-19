/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:40:44 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/19 19:06:47 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_new_node(int value)
{
	t_stack *new_node;
	
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return NULL;
	
	new_node -> value = value;
	new_node -> prev = NULL;
	new_node -> next = NULL;
	
	return new_node;
}

void ft_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack *temp;

	if (!new_node || !stack)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while(temp -> next)
		temp = temp -> next;
	temp -> next = new_node;
	new_node -> prev = temp;
	new_node -> next = NULL;
}

void ft_add_front(t_stack **stack, t_stack *new_node)
{
	if (!stack || !new_node)
		return ;
	if (*stack)
		(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
	new_node -> prev = NULL;
}
void ft_remove_front(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
		
	t_stack *temp;
	temp = *stack;
	*stack = temp->next;
	if (*stack)
		(*stack) -> prev = NULL;
}

void ft_remove_back(t_stack **stack)
{
	t_stack *temp;
	if (!stack)
		return ;
	temp = *stack;
	if(!temp->next)
	{
		*stack = NULL;
		return ;	
	}
	while(temp->next->next)
		temp = temp -> next;
	temp -> next = NULL;
}

int ft_is_duplicate(t_stack *stack, int value)
{
	if (!stack)
		return 0;
	while(stack)
	{
		if (stack -> value == value)
			return 1;
		stack = stack -> next;
	}
	return 0;
}

int ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while(stack->next)
	{
		if (stack->value > stack->next->value)
			return 0;
		stack = stack->next;
	}
	return 1;
}

t_stack *ft_find_max(t_stack **stack)
{
	t_stack *temp;
	t_stack *max;
	if (!stack || !*stack)
		return NULL;
	temp = *stack;
	max = *stack;
	while(temp)
	{
		if (temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return max;
}

t_stack *ft_find_min(t_stack **stack)
{
	t_stack *temp;
	t_stack *min;
	if (!stack || !*stack)
		return NULL;
	temp = *stack;
	min = *stack;
	while(temp->next)
	{
		if (temp->value < min-> value)
			min = temp->value;
		temp = temp->next;
	}
	return min;
}