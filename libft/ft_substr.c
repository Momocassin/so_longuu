/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:37:31 by motaouss          #+#    #+#             */
/*   Updated: 2020/01/04 07:51:42 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	size_t			y;

	y = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(fresh = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (y < len)
	{
		fresh[y] = s[start + y];
		y++;
	}
	fresh[y] = '\0';
	return (fresh);
}
