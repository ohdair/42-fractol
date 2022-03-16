/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:01:01 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/16 15:39:36 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_square(double x)
{
	return (x * x);
}

void	draw_fractal(t_fractol *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			f->fractal.c.re = ((x - WIN_WIDTH / 2) * 3.0 / WIN_WIDTH) - 0.5;
			f->fractal.c.im = ((WIN_HEIGHT / 2) - y) * 2.0 / WIN_HEIGHT;
			f->formula(f);
			my_mlx_pixel_put(f, x, y, initialize_color(f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->mlx.img, 0 , 0);
}

void	julia(t_fractol *f)
{
	t_coordinate	z;

	z = redefine(f->fractal.c.re, f->fractal.c.im);
	f->fractal.iteration = 0;
	while (ft_square(z.re) + ft_square(z.im) <= 4 && \
		f->fractal.iteration < LIMIT)
	{
		z = redefine(ft_square(z.re) - ft_square(z.im) + f->fractal.cj.re, \
				2.0 * z.re * z.im + f->fractal.cj.im);
		f->fractal.iteration++;
	}
}

void	mandelbrot(t_fractol *f)
{
	t_coordinate	z;

	z = redefine(f->fractal.c.re, f->fractal.c.im);
	f->fractal.iteration = 0;
	while (ft_square(z.re) + ft_square(z.im) <= 4 && \
		f->fractal.iteration < LIMIT)
	{
		z = redefine(ft_square(z.re) - ft_square(z.im) + f->fractal.c.re, \
				2.0 * z.re * z.im + f->fractal.c.im);
		f->fractal.iteration++;
	}
}
