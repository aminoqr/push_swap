#include "libft/libft.h"
#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while(stack)
	{
		printf("%d ", stack->value);
		stack = stack -> next;
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int is_valid_input(char *str)
{
	int i = 0;

	if(!str[i])
		return 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if(!str[i])
			return (0);
	}
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			return(0);
		i++;
	}
	return (1);
}

int stack_size(t_stack *stack)
{
	int size;

	size = 1;
	if (!stack)
		return 0;
	while(stack->next)
	{
		size++;
		stack = stack->next;
	}
	return size;
}

void sort_three(t_stack *stack)
{
	if ((stack->value > stack->next->value) && (stack->value > stack->next->next->value))
		
}

int main(int argc, char **argv)
{
	int	i;
	long	temp_val;
	t_stack *stack_a;

	if (argc < 2)
		return (0);
	
	stack_a  = NULL;

	i = 1;
	while(i < argc)
	{
		if (!is_valid_input(argv[i]))
			ft_error();
		temp_val = ft_atoi(argv[i]);
		if (temp_val > 2147483647 || temp_val < -2147483648)
			ft_error();
		if (ft_is_duplicate(stack_a, temp_val))
			ft_error();
		ft_add_back(&stack_a, ft_new_node(temp_val));
		i++;
	}
	print_stack(stack_a);
	if (ft_is_sorted(stack_a) || argc == 2)
	{
		return (0);
	}
}