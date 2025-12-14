/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:39:11 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/14 18:39:43 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_push(t_stack **src, t_stack **dest)
{
	t_stack *temp;
	if (!*src)
		return 0;
	temp = *src;
	ft_remove_front(src);
	ft_add_front(dest, temp);
	return 1;
}

int pa(t_stack **stack_a, t_stack **stack_b)
{
	if(!ft_push(stack_b, stack_a))
		return 0;
	printf("pa\n");
	return 1;
}

int pb(t_stack **stack_a, t_stack **stack_b)
{
	if(!ft_push(stack_a, stack_b))
		return 0;
	printf("pb\n");
	return 1;
}