/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:19:21 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:19:22 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*re;

	if (lst)
	{
		re = ft_lstnew(f(lst->content));
		if (re == NULL)
			return (NULL);
		re->next = ft_lstmap(lst->next, f, del);
		return (re);
	}
	return (NULL);
}
