/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:55:52 by motaouss          #+#    #+#             */
/*   Updated: 2020/01/11 09:54:45 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy;
	size_t			x;

	x = 0;
	copy = (unsigned char *)b;
	while (x < len)
	{
		copy[x] = (unsigned char)c;
		x++;
	}
	return (b);
}
