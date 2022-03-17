/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:39:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/17 11:47:54 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	reset_background(t_fractol *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(f, x, y, 0);
			x++;
		}
		y++;
	}
}

void	rand_color(t_fractol *f)
{
	f->color.red = rand() % 128;
	f->color.green = rand() % 128;
	f->color.blue = rand() % 128;
	f->color.color = create_trgb(0, f->color.red, f->color.green, \
					f->color.blue);
}

void	shift_color(t_fractol *f)
{
	int	t;

	t = f->fractal.iteration;
	if (f->fractal.shift == 1)
	{
		if (f->fractal.iteration < LIMIT)
		{
			f->color.red = sin(0.3 * (double)t) + 64;
			f->color.green = sin(0.3 * (double)t + 3) * 127 + 128;
			f->color.blue = sin(0.3 * (double)t + 2) * 127 + 128;
		}
	}
	if (f->fractal.shift == 2)
	{
		if (f->fractal.iteration < LIMIT)
		{
			f->color.red = sin(0.3 * (double)t + 2) * 127 + 128;
			f->color.green = sin(0.3 * (double)t + 3) * 127 + 128;
			f->color.blue = sin(0.3 * (double)t) + 64;
		}
	}
}

int	initialize_color(t_fractol *f)
{
	if (f->fractal.shift == 0)
	{
		if (f->fractal.iteration < LIMIT)
		{
			f->color.red = 255;
			f->color.green = 255;
			f->color.blue = 255;
		}
	}
	shift_color(f);
	if (f->fractal.iteration == LIMIT)
	{
		f->color.red = 0;
		f->color.green = 0;
		f->color.blue = 0;
	}
	f->color.color = create_trgb(0, f->color.red, f->color.green, \
					f->color.blue);
	return (f->color.color);
}
