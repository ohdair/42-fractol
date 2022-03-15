/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:39:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/15 19:44:01 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	rand_color(t_fractol *f)
{
	f->color.red = rand() % 128;
	f->color.green = rand() % 128;
	f->color.blue = rand() % 128;
	f->color.color = create_trgb(0, f->color.red, f->color.green, \
					f->color.blue);
}

int	initialize_color(t_fractol *f)
{
	double	t;

	t = (double)f->fractal.iteration / f->fractal.limit;
	if ((int)t % 2 != 0)
	{
		f->color.red = 0;
		f->color.green = 0;
		f->color.blue = 0;
	}
	else
	{
		f->color.red = 255;
		f->color.green = 255;
		f->color.blue = 255;
	}
	f->color.color = create_trgb(0, f->color.red, f->color.green, \
					f->color.blue);
	return (f->color.color);
}
