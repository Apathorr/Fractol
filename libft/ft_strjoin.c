/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:11:58 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/18 15:20:58 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	k;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstr = ft_strnew(s1len + s2len);
	if (!newstr)
		return (NULL);
	i = -1;
	k = -1;
	while (++i < s1len)
		newstr[i] = s1[i];
	while (++k < s2len)
		newstr[i++] = s2[k];
	return (newstr);
}
