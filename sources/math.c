/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:38:53 by rsmith            #+#    #+#             */
/*   Updated: 2019/08/22 16:53:01 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_math(t_fractol *fractol)
{
	fractol->z.n = fractol->x / fractol->zoom + fractol->x1;
	fractol->z.i = fractol->y / fractol->zoom + fractol->y1;
	fractol->p = 0;
	while (fractol->z.n * fractol->z.n + fractol->z.i * fractol->z.i < 4
		&& fractol->p < fractol->p_max)
	{
		fractol->tmp = fractol->z.n;
		fractol->z.n = fractol->z.n * fractol->z.n - fractol->z.i *
			fractol->z.i - 0.8 + (fractol->c.n / WIN_WIDTH);
		fractol->z.i = 2 * fractol->z.i * fractol->tmp + fractol->c.i
			/ WIN_WIDTH;
		fractol->p++;
	}
	if (fractol->p == fractol->p_max)
		im_set(fractol->mlx->image, fractol->x, fractol->y, 0xFFFFFF);
	else
		im_set(fractol->mlx->image, fractol->x, fractol->y,
			(fractol->colour * fractol->p));
}

void	mandelbrot_math(t_fractol *fractol)
{
	fractol->c.n = fractol->x / fractol->zoom + fractol->x1;
	fractol->c.i = fractol->y / fractol->zoom + fractol->y1;
	fractol->z.n = 0;
	fractol->z.i = 0;
	fractol->p = 0;
	while (fractol->z.n * fractol->z.n + fractol->z.i * fractol->z.i < 4
		&& fractol->p < fractol->p_max)
	{
		fractol->tmp = fractol->z.n;
		fractol->z.n = fractol->z.n * fractol->z.n - fractol->z.i
			* fractol->z.i +
			fractol->c.n;
		fractol->z.i = 2 * fractol->z.i * fractol->tmp + fractol->c.i;
		fractol->p++;
	}
	if (fractol->p == fractol->p_max)
		im_set(fractol->mlx->image, fractol->x, fractol->y, 0xFFFFFF);
	else
		im_set(fractol->mlx->image, fractol->x, fractol->y,
		(fractol->colour * fractol->p));
}

void	burning_math(t_fractol *fractol)
{
	fractol->c.n = fractol->x / fractol->zoom + fractol->x1;
	fractol->c.i = fractol->y / fractol->zoom + fractol->y1;
	fractol->z.n = 0;
	fractol->z.i = 0;
	fractol->p = 0;
	while (fractol->z.n * fractol->z.n + fractol->z.i * fractol->z.i < 4
		&& fractol->p < fractol->p_max)
	{
		fractol->tmp = fractol->z.n * fractol->z.n - fractol->z.i *
			fractol->z.i + fractol->c.n;
		fractol->z.i = fabs(2 * fractol->z.n * fractol->z.i) + fractol->c.i;
		fractol->z.n = fractol->tmp;
		fractol->p++;
	}
	if (fractol->p == fractol->p_max)
		im_set(fractol->mlx->image, fractol->x, fractol->y, 0xFFFFFF);
	else
		im_set(fractol->mlx->image, fractol->x, fractol->y,
			(fractol->colour * fractol->p));
}

void	tricorn_math(t_fractol *fractol)
{
	fractol->c.n = fractol->x / fractol->zoom + fractol->x1;
	fractol->c.i = fractol->y / fractol->zoom + fractol->y1;
	fractol->z.n = fractol->c.n;
	fractol->z.i = fractol->c.i;
	fractol->p = 0;
	while (fractol->z.n * fractol->z.n + fractol->z.i * fractol->z.i < 4
		&& fractol->p < fractol->p_max)
	{
		fractol->tmp = fractol->z.n * fractol->z.n - fractol->z.i *
			fractol->z.i + fractol->c.n;
		fractol->z.i = -2 * fractol->z.n * fractol->z.i + fractol->c.i;
		fractol->z.n = fractol->tmp;
		fractol->p++;
	}
	if (fractol->p == fractol->p_max)
		im_set(fractol->mlx->image, fractol->x, fractol->y, 0xFFFFFF);
	else
		im_set(fractol->mlx->image, fractol->x, fractol->y,
			(fractol->colour * fractol->p));
}

void	other_math(t_fractol *fractol)
{
	fractol->c.n = fractol->x / fractol->zoom + fractol->x1;
	fractol->c.i = fractol->y / fractol->zoom + fractol->y1;
	fractol->z.n = 0;
	fractol->z.i = 0;
	fractol->p = 0;
	while (fractol->z.n * fractol->z.n + fractol->z.i * fractol->z.i < 4
		&& fractol->p < fractol->p_max)
	{
		fractol->tmp = fractol->z.n;
		fractol->z.n = fractol->z.n * fractol->z.n - fractol->z.i *
			fractol->z.i - .8 + (fractol->c.n / WIN_WIDTH);
		fractol->z.i = (fractol->p % 9) * fractol->z.i * fractol->tmp +
			fractol->c.i / WIN_WIDTH;
		fractol->p++;
	}
	if (fractol->p == fractol->p_max)
		im_set(fractol->mlx->image, fractol->x, fractol->y, 0xFFFFFF);
	else
		im_set(fractol->mlx->image, fractol->x, fractol->y,
			(fractol->colour * fractol->p));
}
