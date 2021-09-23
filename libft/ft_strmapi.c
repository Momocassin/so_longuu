/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 01:54:46 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/25 03:07:50 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	x;

	x = 0;
	if (s == NULL)
		return (0);
	if (!(fresh = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[x] != '\0')
	{
		fresh[x] = f(x, s[x]);
		x++;
	}
	fresh[x] = '\0';
	return (fresh);
}
