/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:16:38 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/19 17:48:39 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intlen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char		*intmax(void)
{
	char	*buffer;

	buffer = ft_strnew(intlen(-2147483648) + 1);
	ft_strcpy(buffer, "-2147483648");
	return (buffer);
}

char			*ft_itoa(int n)
{
	char	*buffer;
	int		i;

	if (n == -2147483648)
		return (intmax());
	buffer = ft_strnew(intlen(n) + 1);
	i = intlen(n) - 1;
	if (buffer)
	{
		if (n < 0)
		{
			buffer[0] = '-';
			n *= -1;
		}
		if (n == 0)
			*buffer = '0';
		while (n > 0)
		{
			buffer[i] = '0' + (n % 10);
			n /= 10;
			i--;
		}
	}
	return (buffer);
}
