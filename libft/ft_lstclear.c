/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasylbye <aasylbye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 21:27:49 by aasylbye          #+#    #+#             */
/*   Updated: 2025/10/12 19:14:22 by aasylbye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	if (!del || !lst)
		return ;
	temp = *lst;
	while (temp)
	{
		del(temp->content);
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*lst = NULL;
}
