/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:38:48 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/19 20:39:27 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	int		n;

	if (!s)
		return ;
	n = ft_strlen(s);
	i = 0;
	while (i < n)
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', fd);
}
