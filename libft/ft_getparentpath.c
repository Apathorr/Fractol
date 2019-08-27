/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparentpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:48:49 by rsmith            #+#    #+#             */
/*   Updated: 2019/03/04 14:27:48 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getparentpath(char *path)
{
	char	*last_slash;
	char	*parent;

	last_slash = ft_strrchr(path, '/');
	parent = ft_strndup(path, last_slash - path);
	return (parent);
}
