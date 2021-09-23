/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:21:24 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:21:25 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	char				*re;
	unsigned int		i;

	i = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	re = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (re == NULL)
		return (NULL);
	while (s[i])
	{
		re[i] = f(i, str[i]);
		i++;
	}
	re[i] = '\0';
	return (re);
}
