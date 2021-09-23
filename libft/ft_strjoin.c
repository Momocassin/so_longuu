/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:34:42 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/25 03:08:40 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (!(s1) || !(s2))
		return (0);
	if (!(fresh = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[x] != '\0')
	{
		fresh[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		fresh[x] = s2[y];
		x++;
		y++;
	}
	fresh[x] = '\0';
	return (fresh);
}
