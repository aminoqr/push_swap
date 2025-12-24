/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:50:00 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/24 18:50:10 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	fill_stack_a(t_stack **a, char **args)
{
	long	val;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_input(args[i]))
			ft_error();
		val = ft_atoi(args[i]);
		if (val > 2147483647 || val < -2147483648)
			ft_error();
		if (ft_is_duplicate(*a, val))
			ft_error();
		ft_add_back(a, ft_new_node(val));
		i++;
	}
}

void	sort_three(t_stack **stack)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack)->value;
	num2 = (*stack)->next->value;
	num3 = (*stack)->next->next->value;
	if (num2 > num3 && num3 > num1)
	{
		rra(stack);
		sa(stack);
	}
	else if (num3 > num1 && num1 > num2)
		sa(stack);
	else if (num2 > num1 && num1 > num3)
		rra(stack);
	else if (num1 > num3 && num3 > num2)
		ra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}
