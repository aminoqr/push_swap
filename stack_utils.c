/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:40:44 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/24 18:53:24 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->target_node = NULL;
	new_node->index = -1;
	new_node->push_cost = 0;
	new_node->above_median = -1;
	new_node->cheapest = 0;
	return (new_node);
}

void	ft_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	if (!new_node || !stack)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	new_node->next = NULL;
}

void	ft_add_front(t_stack **stack, t_stack *new_node)
{
	if (!stack || !new_node)
		return ;
	if (*stack)
		(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
	new_node->prev = NULL;
}

void	ft_remove_front(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;
}

void	ft_remove_back(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = *stack;
	if (!temp->next)
	{
		*stack = NULL;
		return ;
	}
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
}
