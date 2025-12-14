/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:41:59 by aasylbye          #+#    #+#             */
/*   Updated: 2025/10/11 16:13:55 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*sptr;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	sptr = malloc (sizeof(char) * (len + 1));
	if (!sptr)
		return (NULL);
	while (s[i])
	{
		sptr[i] = (*f)(i, s[i]);
		i++;
	}
	sptr[i] = '\0';
	return (sptr);
}
