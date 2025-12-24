/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:50:00 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/24 18:53:24 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	while (b)
	{
		b->cheapest = 0;
		if (b->push_cost < cheapest->push_cost)
			cheapest = b;
		b = b->next;
	}
	cheapest->cheapest = 1;
}

t_stack	*get_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node && *a != cheapest_node->target_node)
			rr(a, b);
	}
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node && *a != cheapest_node->target_node)
			rrr(a, b);
	}
	set_current_position(*a);
	set_current_position(*b);
	prep_for_push(b, cheapest_node, 'b');
	prep_for_push(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	turk_sort(t_stack **a, t_stack **b)
{
	while (stack_size(a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		set_current_position(*a);
		set_current_position(*b);
		set_target_b(*a, *b);
		init_nodes_b(*a, *b);
		set_cheapest(*b);
		move_b_to_a(a, b);
	}
	prep_for_push(a, ft_find_min(*a), 'a');
}
