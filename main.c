/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:37:18 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/24 18:53:24 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	stack_size(t_stack **stack)
{
	int		size;
	t_stack	*temp;

	size = 1;
	if (!*stack || !stack)
		return (0);
	temp = *stack;
	while (temp->next)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	fill_stack_a(&stack_a, args);
	if (ft_is_sorted(stack_a) || stack_size(&stack_a) == 0)
		return (0);
	if (stack_size(&stack_a) == 2)
		sa(&stack_a);
	else if (stack_size(&stack_a) == 3)
		sort_three(&stack_a);
	else
		turk_sort(&stack_a, &stack_b);
	return (0);
}
