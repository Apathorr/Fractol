/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:56:25 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/13 12:02:44 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t bytes;

	bytes = 0;
	while (bytes < len)
	{
		((char *)b)[bytes] = (unsigned char)c;
		bytes++;
	}
	return (b);
}
