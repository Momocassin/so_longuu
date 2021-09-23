/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:59:05 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:09:25 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*copy;
	size_t			x;

	x = 0;
	copy = (unsigned char *)s;
	while (x < n)
	{
		copy[x] = '\0';
		x++;
	}
}
