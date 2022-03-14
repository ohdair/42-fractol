/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:32:59 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/14 16:51:48 by jaewpark         ###   ########.fr       */
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

	f->mouse.pos_x = ((f->fractal.max_x - f->fractal.min_x) / WIN_WIDTH) * \
				x + f->fractal.min_x;
	f->mouse.pos_y = ((f->fractal.max_y - f->fractal.min_y) / WIN_WIDTH) * \
				y + f->fractal.min_y;
	if (mousecode == MOUSE_R_CLK)
		rand_color(f);
	if (mousecode == MOUSE_L_CLK)
		f->mouse.press = !f->mouse.press;
	if (mousecode == MOUSE_UP)
		zoom = 1.20;
	else if (mousecode == MOUSE_DOWN)
		zoom = 0.80;
	else
		zoom = 0.00;
	f->fractal.min_x = scale(f->mouse.pos_x, f->fractal.min_x, zoom);
	f->fractal.min_y = scale(f->mouse.pos_y, f->fractal.min_y, zoom);
	f->fractal.max_x = scale(f->mouse.pos_x, f->fractal.max_x, zoom);
	f->fractal.max_y = scale(f->mouse.pos_y, f->fractal.max_y, zoom);
	draw_fractal(f);
	return (0);
}

int	control_julia(int x, int y, t_fractol *f)
{
	if (f->mouse.press == 1 && f->fractal.type == 1)
	{
		f->fern.x = 4 * ((double)x / WIN_WIDTH - 0.5);
		f->fern.y = 4 * ((double)y / WIN_WIDTH - 0.5);
		draw_fractal(f);
	}
	return (0);
}
