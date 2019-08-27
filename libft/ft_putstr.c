/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:36:19 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/19 17:40:47 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		i;
	int		n;

	if (!s)
		return ;
	n = ft_strlen(s);
	i = 0;
	while (i < n)
		ft_putchar(s[i++]);
	ft_putchar('\0');
}
