/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:35:27 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/13 11:35:28 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int f;

	i = 0;
	f = 0;
	if (!to_find[0])
		return (&str[i]);
	while (str[i])
	{
		while ((str[i + f] == to_find[f]) && to_find[f])
			f++;
		if (!to_find[f])
			return (&str[i]);
		f = 0;
		i++;
	}
	return (0);
}
