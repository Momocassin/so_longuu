/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 08:54:45 by motaouss          #+#    #+#             */
/*   Updated: 2020/01/11 07:57:19 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *copy;

	if (lst)
	{
		while (*lst)
		{
			copy = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = copy;
		}
	}
}
