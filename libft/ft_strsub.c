/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:58:04 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/18 15:02:47 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	if (!s)
		return (NULL);
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len)
		newstr[i++] = s[start++];
	return (newstr);
}
