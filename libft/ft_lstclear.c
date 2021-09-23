/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:18:56 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:18:57 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*cpy;
	int			size;

	size = ft_lstsize(*lst);
	cpy = *lst;
	if (*lst)
	{
		while (0 < size)
		{
			cpy = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = cpy;
			size--;
		}
	}
	(*lst) = NULL;
}
