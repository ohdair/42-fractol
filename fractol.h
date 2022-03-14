/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:43:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/11 21:25:48 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <pthred.h>
# include <time.h>

# include "mlx.h"
# include "mouse.h"
# include "keys.h"
# include "libft.h"

# define FT_SQUARE(x)		(x * x)
# define WIN_WIDTH			(1080)
# define WIN_HEIGHT			(720)
# define SCALE_LIMIT		(500000000)
# define SCALE_PRECISION	(1.420)

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_type
{
	int	 	type;
	int	 	depth;
	int	 	iteration;
	int		limit;
	double	max_x;
	double	max_y;
	double	min_x;
	double	min_y;
	double	x;
	double	y;
}				t_type;

typedef struct	s_mouse
{
	int	press;
	int	pos_x;
	int	pos_y;
}				t_mouse;

typedef struct	s_image
{
	char	*addr;
	int		size;
	int		endian;
	int		bits;
}				t_image;

typedef struct	s_color
{
	int		color;
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_fractol
{
	t_mlx	mlx;
	t_mouse	mouse;
	t_color	color;
	t_type	fractal;
	t_image	image;
	t_fern	fern;
	t_info	info;
}				t_fractol;

typedef struct	s_fern
{
	int		x;
	int		y;
	int		random;
}				t_fern;

typedef struct	s_info
{
	int		title;
	int		julia;
	int		mandelbrot;
	int		fern;
	int		select;
}				t_info;

void			fractol_init(t_fractol *f);
void			fractol_update(t_fractol *f);

int				frac_keys(int keycode, t_fractol *f);
int				frac_mouse(int mousecode, int x, int y, t_fractol *f);

void			frac_pthread(t_fractol *f);
int				f_manipulate(int x, int y, t_fractol *f);
void			color_change(t_fractol *f);

int				mandelbrot(t_fractol *f);
int				julia(t_fractol *f);
int				burningship(t_fractol *f);
int				sphere(t_fractol *f);

#endif
