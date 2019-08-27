/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:41:44 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/19 17:42:18 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int		i;
	int		n;

	if (!s)
		return ;
	n = ft_strlen(s);
	i = 0;
	while (i < n)
		ft_putchar(s[i++]);
	ft_putchar('\n');
}
