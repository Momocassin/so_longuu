/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:10:11 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/09 06:34:05 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		if (((((unsigned char *)s1)[x]) - (((unsigned char *)s2)[x])) != 0)
			return ((((unsigned char *)s1)[x]) - (((unsigned char *)s2)[x]));
		x++;
	}
	return (0);
}
