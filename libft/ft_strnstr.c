/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:04:30 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/25 03:08:29 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t x;
	size_t y;

	x = 0;
	if (!(needle[0]))
		return ((char *)&haystack[x]);
	while (haystack[x] != '\0' && x < len)
	{
		y = 0;
		while (needle[y] != '\0' &&
			(haystack[x + y] == needle[y]) && (x + y) < len)
			y++;
		if (needle[y] == '\0' && x < len)
			return ((char *)&haystack[x]);
		x++;
	}
	return (NULL);
}
