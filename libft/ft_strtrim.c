/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:51:54 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/20 12:17:49 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespaces(char *str, int *i, size_t *n)
{
	while (ft_isspace(*(str + *i)))
		(*i)++;
	while (ft_isspace(*(str + *n)))
		(*n)--;
	if (*i || *n < (size_t)ft_strlen(str))
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	size_t	n;
	int		k;
	char	*newstr;
	size_t	newsize;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	n = ft_strlen(s) - 1;
	if (!whitespaces((char *)s, &i, &n) || !ft_strlen(s))
		return ((char *)s);
	newsize = ((size_t)i == ft_strlen(s) ? 0 : ft_strlen(s) - (size_t)i - \
	(ft_strlen(s) - n));
	newstr = ft_strnew(newsize + 1);
	if (!newstr)
		return (NULL);
	while (i <= (int)n)
		newstr[k++] = s[i++];
	return (newstr);
}
