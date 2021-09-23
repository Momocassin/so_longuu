/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:21:35 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:21:37 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		n;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		n = 0;
		while (needle[n] == haystack[i] && haystack[i] && needle[n] && i < len)
		{
			n++;
			i++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + (i - n));
		i = i - n;
		i++;
	}
	return (NULL);
}
