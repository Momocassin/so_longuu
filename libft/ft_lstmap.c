/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:47:00 by motaouss          #+#    #+#             */
/*   Updated: 2020/01/11 09:08:46 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (0);
	tmp = 0;
	while (lst)
	{
		if (!(copy = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&tmp, del);
			return (0);
		}
		ft_lstadd_back(&tmp, copy);
		lst = lst->next;
	}
	return (tmp);
}
