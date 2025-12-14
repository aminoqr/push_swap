/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:46:30 by aasylbye          #+#    #+#             */
/*   Updated: 2025/10/09 21:39:12 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_string(long nbr, char *str, int digit)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		str[i] = '-';
		i++;
		nbr *= -1;
	}
	str[digit] = '\0';
	while (digit > i)
	{
		str[digit - 1] = ((nbr % 10) + '0');
		nbr /= 10;
		digit--;
	}
}

int	digit_count(long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr >= 10)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	long	num;

	num = n;
	digit = digit_count(num);
	str = malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	fill_string(num, str, digit);
	return (str);
}
