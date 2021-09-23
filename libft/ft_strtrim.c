/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:43:51 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:11:39 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	x;
	size_t	y;

	if (!s || !set)
		return (NULL);
	x = 0;
	while (s[x] && (ft_strchr(set, s[x]) != NULL))
		x++;
	y = ft_strlen(&s[x]);
	if (y != 0)
	{
		while (s[y + x - 1] && (ft_strchr(set, s[y + x - 1]) != NULL))
			y--;
	}
	return (ft_substr(s, x, y));
}
