/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:43:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/16 20:12:07 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

# include "mlx.h"

# define WIDTH	1000
# define HEIGHT	1000
# define LIMIT	142
# define ZOOM	1.20


typedef struct s_coordinate
{
	double	re;
	double	im;
}t_coordinate;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}t_mlx;

typedef struct s_type
{
	int		type;
	int		iteration;
	int		shift;
	double			ratio;
	double			pixel;
	t_coordinate	center;
	t_coordinate	c;
	t_coordinate	cj;
}t_type;

typedef struct s_mouse
{
	int	press;
	int	pos_x;
	int	pos_y;
}t_mouse;

typedef struct s_image
{
	char	*addr;
	int		size;
	int		endian;
	int		bits;
}t_image;

typedef struct s_color
{
	int		color;
	int		red;
	int		green;
	int		blue;
}t_color;

typedef struct s_fern
{
	double	x;
	double	y;
	int		random;
}t_fern;

typedef struct s_info
{
	int		*title;
	int		*ju;
	int		*ma;
	int		*fe;
	int		select;
}t_info;

typedef struct s_fractol
{
	t_mlx	mlx;
	t_mouse	mouse;
	t_color	color;
	t_type	fractal;
	t_image	image;
	t_fern	fern;
	t_info	info;
	void	(*formula)(struct s_fractol *);
}t_fractol;

t_coordinate	redefine(double re, double im);
void			my_mlx_pixel_put(t_fractol *f, int x, int y, int color);
int				render_next_frame(t_fractol *f);

void			initialize_limits(t_fractol *f);
void			add_info_menu(t_fractol *f);
void			select_info_menu(t_fractol *f);

void			draw_fractal(t_fractol *f);
void			mandelbrot(t_fractol *f);
void			julia(t_fractol *f);
double			ft_square(double x);

void			init_fern_fractal(t_fractol *f);
void			fern_fractal(t_fractol *f);
void			fern_create_pixels(t_fractol *f);

int				control_keys(int keycode, t_fractol *f);
int				control_mouse(int mousecode, int x, int y, t_fractol *f);
int				control_julia(int x, int y, t_fractol *f);

int				create_trgb(int t, int red, int green, int blue);
void			reset_background(t_fractol *f);
void			rand_color(t_fractol *f);
int				initialize_color(t_fractol *f);

#endif
