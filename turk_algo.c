/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:02:55 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/23 16:56:46 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_stack *get_target_node(t_stack *a, int b_val)
{
    t_stack *target_node;
	t_stack *temp;

	temp = a;
	target_node = NULL;
	while(a)
	{
		if(a->value > b_val)
		{
			if(!target_node || target_node->value > a->value)
				target_node = a;
		}
		a = a->next;
	}
	if (!target_node)
		return ft_find_min(&temp);
	return target_node;
}

void set_target_b(t_stack *a, t_stack *b)
{
	while(b)
	{
		b -> target_node = get_target_node(a, b->value);
		b = b -> next;
	}
	return ;
}

void init_nodes_b(t_stack *a, t_stack *b)
{
    int len_a;
    int len_b;

    len_a = stack_size(&a);
    len_b = stack_size(&b);
    while (b)
    {
        b->push_cost = b->index;
        if (b->above_median && b->target_node->above_median)
            b->push_cost = (b->index > b->target_node->index) ? 
                           b->index : b->target_node->index;
        else if (!b->above_median && !b->target_node->above_median)
            b->push_cost = ((len_b - b->index) > (len_a - b->target_node->index)) ? 
                           (len_b - b->index) : (len_a - b->target_node->index);
        else
            b->push_cost = ((b->above_median) ? b->index : (len_b - b->index)) + 
                           ((b->target_node->above_median) ? 
                           b->target_node->index : (len_a - b->target_node->index));
        b = b->next;
    }
}

void set_cheapest(t_stack *b)
{
	t_stack *cheapest;
	
	cheapest = b;
	while(b)
	{
		b->cheapest = 0;
		if(b->push_cost < cheapest->push_cost)
			cheapest = b;
		b = b-> next;
	}
	cheapest -> cheapest = 1;
}

t_stack *get_cheapest_node(t_stack *stack)
{
	
}

void turk_sort(t_stack **a, t_stack **b)
{
	while(stack_size(a) > 3)
		pb(a, b);
	sort_three(a);
}