/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:38:45 by rsmith            #+#    #+#             */
/*   Updated: 2019/08/21 10:22:49 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH	1000
# define WIN_HEIGHT	1000
# define THREADS 16
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"


typedef struct	s_mouse
{
	int			isclick;
	int			lastx;
	int			lasty;
	int			x;
	int			y;
}				t_mouse;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;

}				t_mlx;
typedef struct  s_complex
{
	double		n;
	double		i;
}				t_complex;

typedef struct  s_fractol
{
t_mlx			*mlx;
int				fractol;
int				colour;
int				strobe;
int				c_set;
int				x;
int				y;
int				y_max;
int				p;
int				p_max;
double			zoom;
double			x1;
double			y1;
t_complex		c;
t_complex		z;
double			tmp;
int				mouse_julia;
}				t_fractol;

void	im_set(t_image *image, int x, int y, int colour);
void	clear_im(t_image *image);
t_image	*del_im(t_mlx *mlx, t_image *image);
t_image *new_im(t_mlx *mlx);
void 	colourset(t_fractol *fractol, int setnum);

void	zoom_in(int x, int y, t_fractol *fractol);
void	zoom_out(int x, int y, t_fractol *fractol);
int		mouse_hook(int mousecode, int x, int y, t_fractol *fractol);
int		key_hook(int key, t_fractol *fractol);

void	run_threads(t_fractol *fractol);
void	fractol_init(t_fractol *fractol);
void	init_mlx(t_mlx *mlx);

void	error();
void	setup(t_fractol *fractol, t_mlx *mlx);

void	julia_math(t_fractol *fractol);
void	mandelbrot_math(t_fractol *fractol);
void	burning_math(t_fractol *fractol);
void	tricorn_math(t_fractol *fractol);
void	other_math(t_fractol *fractol);


int		mouse_on(int x, int y, t_fractol *fractol);
void	print_help(t_mlx *mlx);

#endif
