/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:01:07 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/03 17:06:03 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (dst[x] != '\0' && x < size)
		x++;
	while (src[y] != '\0' && (x + y + 1) < size)
	{
		dst[x + y] = src[y];
		y++;
	}
	if (x != size)
		dst[x + y] = '\0';
	while (src[y] != '\0')
		y++;
	return (x + y);
}
