/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:00:58 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:10:22 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		x;
	t_list	*copy;

	copy = lst;
	x = 0;
	if (copy)
	{
		while (copy)
		{
			copy = copy->next;
			x++;
		}
	}
	return (x);
}
