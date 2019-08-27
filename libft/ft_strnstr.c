/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:13:22 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/14 16:43:01 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*copy;
	char	*buffer;
	size_t	length;

	buffer = (char *)(s1 + n);
	length = ft_strlen(s2);
	copy = (char *)s1;
	if (!length)
		return ((char *)s1);
	while ((copy = ft_strchr(copy, *s2)) && copy <= buffer)
	{
		if ((copy + length <= buffer) && !ft_strncmp(copy, s2, length))
			return (copy);
		copy++;
	}
	return (NULL);
}
