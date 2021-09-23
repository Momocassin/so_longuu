/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:22:09 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/09 07:01:49 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*dest;
	int		x;

	x = 0;
	while (s1[x] != '\0')
		x++;
	if (!(dest = malloc(sizeof(*dest) * (x + 1))))
		return (0);
	x = 0;
	while (s1[x] != '\0')
	{
		dest[x] = s1[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
