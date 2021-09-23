/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 08:59:50 by motaouss          #+#    #+#             */
/*   Updated: 2020/01/11 07:49:44 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*copy;

	copy = (*alst);
	if (!(*alst))
		*alst = new;
	else
	{
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
}
