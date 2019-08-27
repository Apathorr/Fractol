/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:22:25 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/19 14:48:33 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char *s, char c)
{
	int		words;

	while (*s && *s == c)
		s++;
	words = (*s) ? 1 : 0;
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			words++;
		s++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	*start;
	char	**res;

	if (!s || !c)
		return (NULL);
	words = wordcount((char *)s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	start = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(res++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		s++;
	}
	if (start != s)
		*(res++) = ft_strsub(start, 0, s - start);
	*res = NULL;
	return (res - words);
}
