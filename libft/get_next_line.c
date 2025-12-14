/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:47:49 by aasylbye          #+#    #+#             */
/*   Updated: 2025/11/01 15:06:04 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_stash(int fd, char *stash)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 2) * sizeof(char));
	if (!buff)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	rd_bytes = 1;
	while (!ft_strchr(stash, '\n') && rd_bytes > 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		stash = ft_strjoin_free(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*ft_final_line(char *stash)
{
	int		i;
	char	*holder;

	holder = malloc((ft_strlen(stash) + 2) * sizeof(char));
	if (!holder)
		return (NULL);
	i = 0;
	if (!ft_strchr(stash, '\n'))
	{
		while (stash[i])
		{
			holder[i] = stash[i];
			i++;
		}
		holder[i] = '\0';
		return (holder);
	}
	while (stash[i] && stash[i] != '\n')
	{
		holder[i] = stash[i];
		i++;
	}
	holder[i] = '\n';
	holder[i + 1] = '\0';
	return (holder);
}

char	*ft_new_stash(char *stash)
{
	int		i;
	int		i_h;
	char	*holder;

	if (!ft_strchr(stash, '\n'))
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (stash[i] != '\n')
		i++;
	i++;
	holder = malloc((ft_strlen(stash + i) + 1) * sizeof(char));
	if (!holder)
		return (NULL);
	i_h = -1;
	while (stash[i])
	{
		holder[++i_h] = stash[i];
		i++;
	}
	holder[i_h + 1] = '\0';
	free(stash);
	return (holder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_final_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}
