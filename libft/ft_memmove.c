/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:52:45 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/25 03:17:31 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = (char*)dest;
	s = (const char*)src;
	if (s == d)
		return (dest);
	if (d > s)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
		{
			*d-- = *s--;
		}
	}
	else
	{
		while (n)
		{
			*d++ = *s++;
			n--;
		}
	}
	return (dest);
}
