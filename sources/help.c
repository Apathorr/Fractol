/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:32:42 by rsmith            #+#    #+#             */
/*   Updated: 2019/08/19 19:25:36 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->window, 42, 42, 0xFFFFFF, "Controls");
	mlx_string_put(mlx->mlx, mlx->window, 42, 72, 0xFFFFFF,
	"Mouse wheel or right and left click to zoom");
	mlx_string_put(mlx->mlx, mlx->window, 42, 102, 0xFFFFFF,
	"+/- to increase or decrease iterations");
	mlx_string_put(mlx->mlx, mlx->window, 42, 282, 0xFFFFFF,
	"Space bar to enable mouse control for Julia");
	mlx_string_put(mlx->mlx, mlx->window, 42, 132, 0xFFFFFF,
	"Control to enable \"strobe mode\"");
	mlx_string_put(mlx->mlx, mlx->window, 42, 162, 0xFFFFFF,
	"Arrow keys to change colour sets");
	mlx_string_put(mlx->mlx, mlx->window, 42, 192, 0xFFFFFF,
	"O to go backwards a fractol");
	mlx_string_put(mlx->mlx, mlx->window, 42, 222, 0xFFFFFF,
	"P to go forward a fractol");
	mlx_string_put(mlx->mlx, mlx->window, 42, 252, 0xFFFFFF,
	"R to reset");
	mlx_string_put(mlx->mlx, mlx->window, 42, 312, 0xFFFFFF, "Quit: ESC");
}

void	error(void)
{
	ft_putstr("Usage: /fractol \"mandlebrot\", ");
	ft_putendl("\"julia\", \"burningship\", \"tricorn\" \"other\"");
}

void	setup(t_fractol *fractol, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx,
		WIN_WIDTH, WIN_HEIGHT, "Fractol");
	mlx->image = new_im(mlx);
	fractol->mlx = mlx;
	fractol_init(fractol);
	mlx_hook(mlx->window, 6, 0, mouse_on, fractol);
	mlx_mouse_hook(mlx->window, mouse_hook, fractol);
	mlx_key_hook(mlx->window, key_hook, fractol);
	mlx_loop(mlx->mlx);
}
