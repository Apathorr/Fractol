/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:33:10 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/13 13:49:17 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char *dup;

	dup = (char*)malloc(sizeof(*dup) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, src);
	return (dup);
}
