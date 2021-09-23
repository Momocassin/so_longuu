/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 09:02:54 by motaouss          #+#    #+#             */
/*   Updated: 2020/01/06 09:17:45 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_words(char const *s, char c)
{
	size_t		words;
	size_t		i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char		*ft_copy(char *dest, char const *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char		*malloc_words(char const *str, char c)
{
	char		*s;
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (0);
	s = ft_copy(s, str, i);
	return (s);
}

static char		**ft_free(char **tab)
{
	size_t		i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		size;

	if (!s)
		return (0);
	i = 0;
	if (!(tab = malloc(sizeof(char *) * (nb_words(s, c) + 1))))
		return (0);
	tab[nb_words(s, c)] = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
			if (!(tab[size] = malloc_words((s + i), c)))
				return (ft_free(tab));
		size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab);
}
