/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:55:46 by rsmith            #+#    #+#             */
/*   Updated: 2019/08/22 16:57:22 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*run_math(void *tab)
{
	t_fractol	*fractol;
	int			tmp;

	fractol = (t_fractol*)tab;
	fractol->x = 0;
	tmp = fractol->y;
	while (fractol->x < WIN_WIDTH)
	{
		fractol->y = tmp - 1;
		while (++fractol->y < fractol->y_max)
		{
			if (fractol->fractol == 0)
				mandelbrot_math(fractol);
			if (fractol->fractol == 1)
				julia_math(fractol);
			if (fractol->fractol == 2)
				burning_math(fractol);
			if (fractol->fractol == 3)
				tricorn_math(fractol);
			if (fractol->fractol == 4)
				other_math(fractol);
		}
		fractol->x++;
	}
	return (tab);
}

void	run_threads(t_fractol *fractol)
{
	t_fractol	tab[THREADS];
	pthread_t	t[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy((void*)&tab[i], (void*)fractol, sizeof(t_fractol));
		tab[i].y = (WIN_WIDTH / THREADS) * i;
		tab[i].y_max = (WIN_WIDTH / THREADS) * (i + 1);
		pthread_create(&t[i], NULL, run_math, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fractol->mlx->mlx, fractol->mlx->window,
		fractol->mlx->image->image, 0, 0);
	print_help(fractol->mlx);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->p_max = 50;
	fractol->zoom = 200;
	fractol->x1 = -2.0f;
	fractol->y1 = -2.0f;
	fractol->c_set = 1;
	colourset(fractol, fractol->c_set);
	fractol->strobe = 0;
	if (fractol->fractol == 1)
	{
		fractol->mouse_julia = 1;
		fractol->c.n = 0.285;
		fractol->c.i = 0.01;
	}
	if (fractol->fractol == 4)
		fractol->zoom = 1;
	run_threads(fractol);
}

int		fractol_select(char **argv, t_fractol *fractol)
{
	if (!ft_strcmp(argv[1], "mandelbrot"))
		fractol->fractol = 0;
	else if (!ft_strcmp(argv[1], "julia"))
		fractol->fractol = 1;
	else if (!ft_strcmp(argv[1], "burningship"))
		fractol->fractol = 2;
	else if (!ft_strcmp(argv[1], "tricorn"))
		fractol->fractol = 3;
	else if (!ft_strcmp(argv[1], "other"))
		fractol->fractol = 4;
	else
	{
		error();
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_fractol	*fractol;
	t_mlx		*mlx;

	if (argc == 2)
	{
		if (!(fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol))) ||
			!(mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx))))
			return (-1);
		if (!fractol_select(argv, fractol))
			return (0);
		setup(fractol, mlx);
	}
	else
		error();
	return (0);
}
