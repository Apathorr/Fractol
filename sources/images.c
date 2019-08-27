/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:38:08 by rsmith            #+#    #+#             */
/*   Updated: 2019/08/19 11:43:42 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	im_set(t_image *image, int x, int y, int colour)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int*)(image->ptr + ((x + y * WIN_WIDTH) * image->bpp)) = colour;
}

void	clear_im(t_image *image)
{
	ft_bzero(image->ptr, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

t_image	*del_im(t_mlx *mlx, t_image *image)
{
	if (image != NULL)
	{
		if (image->image)
			mlx_destroy_image(mlx->mlx, image->image);
		ft_memdel((void**)&image);
	}
	return (NULL);
}

t_image	*new_im(t_mlx *mlx)
{
	t_image *image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(image->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)))
		return (del_im(mlx, image));
	image->ptr = mlx_get_data_addr(image->image, &image->bpp, &image->stride,
		&image->endian);
	image->bpp /= 8;
	return (image);
}

void	colourset(t_fractol *fractol, int setnum)
{
	if (setnum == 1)
		fractol->colour = 0x080000;
	if (setnum == 2)
		fractol->colour = 0x000800;
	if (setnum == 3)
		fractol->colour = 0x000008;
	if (setnum == 4)
		fractol->colour = 0x000808;
	if (setnum == 5)
		fractol->colour = 0x080008;
	if (setnum == 6)
		fractol->colour = 0xD1F2B9;
	if (setnum == 7)
		fractol->colour = 0x123456;
	if (setnum == 8)
		fractol->colour = 0x36EFA5;
	if (setnum == 9)
		fractol->colour = 0x06BB06;
	if (setnum == 0)
		fractol->colour = 0x080800;
}
