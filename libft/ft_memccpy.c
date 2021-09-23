/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:19:38 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:19:40 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*str;
	int				x;

	x = 0;
	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	i = 0;
	while (i < n && x == 0)
	{
		if (str[i] == (unsigned char)c)
			x = i + 1;
		dst[i] = str[i];
		i++;
	}
	if (x == 0)
		return (NULL);
	else
		return ((void *)dst + x);
}
