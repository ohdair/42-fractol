/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:39:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/15 16:58:39 by jaewpark         ###   ########.fr       */
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
	f->color.red = (int)(9 * (1 - t) * ft_square(t)) % 255;
	f->color.green = (int)(9 * ft_square(1 - t) * ft_square(t)) % 255;
	f->color.blue = (int)(9 * ft_square(1 - t) * t) % 255;
	f->color.color = create_trgb(0, f->color.red, f->color.green, \
					f->color.blue);
	return (f->color.color);
}
