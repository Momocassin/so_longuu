/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:19:56 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:19:57 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*de;
	char	*s;
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	de = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		de[i] = s[i];
		i++;
	}
	return ((void *)de);
}
