/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:21:04 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:21:05 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		n;

	n = 0;
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[n] && dstsize > (i + n + 1))
	{
		dst[i + n] = src[n];
		n++;
	}
	if (i != dstsize)
		dst[i + n] = '\0';
	return (i + ft_strlen(src));
}
