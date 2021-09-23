/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:22:06 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:22:07 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*re;
	size_t	i;

	str = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	re = malloc(sizeof(char) * len + 1);
	if (re == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		re[0] = '\0';
		return (re);
	}
	while (i < len && str[start])
	{
		re[i] = str[start];
		start++;
		i++;
	}
	re[i] = '\0';
	return (re);
}
