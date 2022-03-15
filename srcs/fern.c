/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:09:35 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/15 16:49:10 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fern_fractal(t_fractol *f)
{
	f->fractal.x = 0.0;
	f->fractal.y = 0.0;
	f->fractal.iteration = 11000;
	f->color.red = 0;
	f->color.green = 0;
	f->color.blue = 0;
	f->color.color = create_trgb(0, 0, 100, 0);
	f->fern.x = 0.0;
	f->fern.y = 0.0;
}

void	fern_fractal(t_fractol *f)
{
	int	iter;

	iter = f->fractal.iteration;
	while (iter > 0)
	{
		fern_create_pixels(f);
		my_mlx_pixel_put(f, 180 * f->fern.x + WIN_WIDTH / 2.4, \
					WIN_HEIGHT - 100 * f->fern.y, f->color.color);
		f->fractal.x = f->fern.x;
		f->fractal.y = f->fern.y;
		iter--;
	}
}

void	fern_create_pixels(t_fractol *f)
{
	f->fern.random = rand() % 100;
	if (f->fern.random == 0)
	{
		f->fern.x = 0.0;
		f->fern.y = 0.16 * f->fractal.y;
	}
	else if (f->fern.random >= 1 && f->fern.random <= 85)
	{
		f->fern.x = 0.85 * f->fractal.x + 0.04 * f->fractal.y;
		f->fern.y = -0.04 * f->fractal.x + 0.85 * f->fractal.y + 1.6;
	}
	else if (f->fern.random >= 87 && f->fern.random <= 92)
	{
		f->fern.x = 0.2 * f->fractal.x - 0.26 * f->fractal.y;
		f->fern.y = 0.23 * f->fractal.x + 0.22 * f->fractal.y + 1.6;
	}
	else
	{
		f->fern.x = -0.15 * f->fractal.x + 0.28 * f->fractal.y;
		f->fern.y = 0.26 * f->fractal.x + 0.24 * f->fractal.y + 0.44;
	}
}
