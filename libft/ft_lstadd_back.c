/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:18:44 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:18:45 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*lst;

	if (!*alst)
		*alst = new;
	else if (*alst)
	{
		lst = *alst;
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
}
