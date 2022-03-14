/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:39:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/11 23:40:00 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		create_trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

void		rand_color(t_fractol *f)
{
	f->color.red = rand() % 128;
	f->color.green = rand() % 128;
	f->color.blue = rand() % 128;
}

int		initialize_color(t_fractol *f)
{
	double	t;

	t = (double)f->fractal.iteration / f->fractal.limit;
	t->color.red = 9 * (1 - t) * FT_SQUARE(t);
	t->color.green = 9 * FT_SQUARE(1 - t) * FT_SQUARE(t);
	t->color.blue = 9 * FT_SQUARE(1 - t) * t;
	t->color.color = create_trgb(0, t->color.red, t->color.green, \
					t->color.blue);
}

