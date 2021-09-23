/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 08:59:50 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:09:48 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
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
