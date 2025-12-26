/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:00:00 by aasylbye          #+#    #+#             */
/*   Updated: 2025/12/25 13:49:35 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_everything(char **dptr, int last)
{
	while (last >= 0)
	{
		free(dptr[last]);
		last--;
	}
	free(dptr);
}

static int	word_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	splitter(char **dptr, char *s, char c)
{
	int	si;
	int	di;
	int	dj;

	si = 0;
	di = 0;
	while (s[si])
	{
		while (s[si] == c)
			si++;
		if (!s[si])
			break ;
		dptr[di] = malloc(sizeof(char) * (word_len(&s[si], c) + 1));
		if (!dptr[di])
			return (free_everything(dptr, di - 1), 0);
		dj = 0;
		while (s[si] && s[si] != c)
			dptr[di][dj++] = s[si++];
		dptr[di++][dj] = '\0';
	}
	return (1);
}

static int	word_counter(char *s, char c)
{
	int	i;
	int	is_word;
	int	word_count;

	i = 0;
	word_count = 0;
	is_word = 0;
	while (s[i])
	{
		if (!is_word && s[i] != c)
		{
			word_count++;
			is_word = 1;
		}
		else if (is_word && s[i] == c)
			is_word = 0;
		i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**dptr;
	int		word_num;

	if (!s)
		return (NULL);
	word_num = word_counter((char *)s, c);
	dptr = malloc(sizeof(char *) * (word_num + 1));
	if (!dptr)
		return (NULL);
	if (!splitter(dptr, (char *)s, c))
		return (NULL);
	dptr[word_num] = NULL;
	return (dptr);
}
