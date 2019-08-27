/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:51:02 by rsmith            #+#    #+#             */
/*   Updated: 2019/08/19 13:28:37 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_fractol *fractol)
{
	fractol->x1 = (x / fractol->zoom + fractol->x1) -
		(x / (fractol->zoom * 1.5));
	fractol->y1 = (y / fractol->zoom + fractol->y1) -
		(y / (fractol->zoom * 1.5));
	fractol->zoom *= 1.5;
	fractol->p_max++;
}

void	zoom_out(int x, int y, t_fractol *fractol)
{
	fractol->x1 = (x / fractol->zoom + fractol->x1) -
		(x / (fractol->zoom / 1.5));
	fractol->y1 = (y / fractol->zoom + fractol->y1) -
		(y / (fractol->zoom / 1.5));
	fractol->zoom /= 1.5;
	fractol->p_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *fractol)
{
	if (mousecode == 4 || mousecode == 1)
		zoom_in(x, y, fractol);
	else if (mousecode == 5 || mousecode == 2)
		zoom_out(x, y, fractol);
	run_threads(fractol);
	return (0);
}

int		mouse_on(int x, int y, t_fractol *fractol)
{
	if (fractol->fractol == 1 && fractol->mouse_julia == 1)
	{
		fractol->c.n = x * 2;
		fractol->c.i = y * 2 - 800;
	}
	if (fractol->strobe == 1)
	{
		if ((fractol->colour + (x - y) < 0))
			fractol->colour = 0x202020;
		fractol->colour = (fractol->colour + (x - y));
	}
	run_threads(fractol);
	return (0);
}

int		key_hook(int key, t_fractol *fractol)
{
	if (key == 53)
		exit(0);
	else if (key == 69 || key == 24)
		fractol->p_max = fractol->p_max >= 20 ? (fractol->p_max * 1.125) : 20;
	else if (key == 78 || key == 27)
		fractol->p_max = (fractol->p_max / 1.125);
	else if (key == 49)
		fractol->mouse_julia = fractol->mouse_julia == 1 ? 0 : 1;
	else if (key == 256)
		fractol->strobe = fractol->strobe == 1 ? 0 : 1;
	else if (key == 126 || key == 124)
		fractol->c_set = fractol->c_set == 9 ? 0 : fractol->c_set + 1;
	else if (key == 125 || key == 123)
		fractol->c_set = fractol->c_set == 0 ? 9 : fractol->c_set - 1;
	else if (key == 31)
		fractol->fractol = fractol->fractol == 0 ? 4 : fractol->fractol - 1;
	else if (key == 35)
		fractol->fractol = fractol->fractol == 4 ? 0 : fractol->fractol + 1;
	else if (key == 15)
		fractol_init(fractol);
	colourset(fractol, fractol->c_set);
	run_threads(fractol);
	return (0);
}
