/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:42:29 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/13 13:35:51 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t bytes;

	bytes = 0;
	while (bytes < n)
	{
		*((unsigned char *)dst + bytes) = *((unsigned char *)src + bytes);
		if (*((unsigned char*)src + bytes) == (unsigned char)c)
			return ((unsigned char *)dst + bytes + 1);
		bytes++;
	}
	return (NULL);
}
