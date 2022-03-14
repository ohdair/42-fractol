/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:01:01 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/14 16:47:06 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_square(int x)
{
	return (x * x);
}

void	draw_fractal(t_fractol *f)
{
	int		x;
	int		y;
	double	tmp_x;
	double	tmp_y;

	tmp_x = (f->fractal.max_x - f->fractal.min_x) / WIN_WIDTH;
	tmp_y = (f->fractal.max_y - f->fractal.min_y) / WIN_HEIGHT;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			f->fractal.y = f->fractal.max_y - y * tmp_y;
			f->fractal.x = f->fractal.min_x + x * tmp_x;
			my_mlx_pixel_put(f, x, y, initialize_color(f));
			x++;
		}
		y++;
	}
}

void	julia(t_fractol *f)
{
	double	zr;
	double	zi;
	double	tmp;

	zr = f->fractal.x;
	zi = f->fractal.y;
	f->fractal.iteration = 0;
	while (ft_square(zr) + ft_square(zi)
		<= 4 && f->fractal.iteration < f->fractal.limit)
	{
		tmp = ft_square(zr) - ft_square(zi) + f->fern.x;
		zi = 2.0 * zr * zi + f->fern.y;
		zr = tmp;
		f->fractal.iteration++;
	}
}

void	mandelbrot(t_fractol *f)
{
	double	zr;
	double	zi;
	double	tmp;

	zr = f->fractal.x;
	zi = f->fractal.y;
	f->fractal.iteration = 0;
	while (ft_square(zr) + ft_square(zi)
		<= 4 && f->fractal.iteration < f->fractal.limit)
	{
		tmp = ft_square(zr) - ft_square(zi) + f->fractal.x;
		zi = 2.0 * zr * zi + f->fractal.y;
		zr = tmp;
		f->fractal.iteration++;
	}
}
