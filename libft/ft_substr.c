/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:37:31 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:11:51 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	y;

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
