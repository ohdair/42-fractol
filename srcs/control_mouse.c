/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:32:59 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/15 19:39:57 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "usagekeys.h"

static int	scale(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int	control_mouse(int mousecode, int x, int y, t_fractol *f)
{
	double	zoom;

	f->mouse.pos_x = ((f->fractal.max.re - f->fractal.min.re) / WIN_WIDTH) * \
				x + f->fractal.min.re;
	f->mouse.pos_y = ((f->fractal.max.im - f->fractal.min.im) / WIN_WIDTH) * \
				y + f->fractal.min.im;
	if (mousecode == MOUSE_R_CLK)
		rand_color(f);
	if (mousecode == MOUSE_L_CLK)
		f->mouse.press = !f->mouse.press;
	if (mousecode == MOUSE_UP)
		zoom = 1.20;
	else if (mousecode == MOUSE_DOWN)
		zoom = 0.80;
	else
		zoom = 1.00;
	f->fractal.min.re = scale(f->mouse.pos_x, f->fractal.min.re, zoom);
	f->fractal.min.im = scale(f->mouse.pos_y, f->fractal.min.im, zoom);
	f->fractal.max.re = scale(f->mouse.pos_x, f->fractal.max.re, zoom);
	f->fractal.max.im = scale(f->mouse.pos_y, f->fractal.max.im, zoom);
	draw_fractal(f);
	return (0);
}

int	control_julia(int x, int y, t_fractol *f)
{
	if (f->mouse.press == 1 && f->fractal.type == 1)
	{
		f->fractal.cj = redefine(4 * ((double) x / WIN_WIDTH - 0.5), \
						4 * ((double)(WIN_HEIGHT - y) / WIN_HEIGHT - 0.5));
		draw_fractal(f);
	}
	return (0);
}
