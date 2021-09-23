/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:14:11 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/24 04:18:42 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t x;

	x = 0;
	if (!dst && !src)
		return (NULL);
	while (x < n)
	{
		((char *)dst)[x] = ((char *)src)[x];
		x++;
	}
	return (dst);
}
