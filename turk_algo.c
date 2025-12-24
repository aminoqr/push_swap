/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:02:55 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/24 18:53:24 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_target_node(t_stack *a, int b_val)
{
	t_stack	*target_node;
	t_stack	*temp;

	temp = a;
	target_node = NULL;
	while (a)
	{
		if (a->value > b_val)
		{
			if (!target_node || target_node->value > a->value)
				target_node = a;
		}
		a = a->next;
	}
	if (!target_node)
		return (ft_find_min(temp));
	return (target_node);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	while (b)
	{
		b->target_node = get_target_node(a, b->value);
		b = b->next;
	}
}

static int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	calc_push_cost(t_stack *b, int len_a, int len_b)
{
	int	cost_b;
	int	cost_a;

	b->push_cost = b->index;
	if (b->above_median && b->target_node->above_median)
		b->push_cost = get_max(b->index, b->target_node->index);
	else if (!b->above_median && !b->target_node->above_median)
	{
		cost_b = len_b - b->index;
		cost_a = len_a - b->target_node->index;
		b->push_cost = get_max(cost_b, cost_a);
	}
	else
	{
		if (b->above_median)
			cost_b = b->index;
		else
			cost_b = len_b - b->index;
		if (b->target_node->above_median)
			cost_a = b->target_node->index;
		else
			cost_a = len_a - b->target_node->index;
		b->push_cost = cost_b + cost_a;
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(&a);
	len_b = stack_size(&b);
	while (b)
	{
		calc_push_cost(b, len_a, len_b);
		b = b->next;
	}
}
