/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:32:59 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/16 20:41:31 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "usagekeys.h"

void	mouse_wheel(int mousecode, int x, int y, t_fractol *f)
{
	f->mouse.pos_x = (x - (WIDTH / 2)) * f->fractal.ratio / WIDTH;
	f->mouse.pos_y = (y - (HEIGHT / 2)) * f->fractal.ratio / HEIGHT;
	if (mousecode == MOUSE_UP)
	{
		f->fractal.center.re -= f->mouse.pos_x * 0.3;
		f->fractal.center.im -= f->mouse.pos_y * 0.3;
		f->fractal.ratio /= ZOOM;
	}
	if (mousecode == MOUSE_DOWN)
	{
		f->fractal.center.re -= f->mouse.pos_x * 0.3;
		f->fractal.center.im -= f->mouse.pos_y * 0.3;
		f->fractal.ratio *= ZOOM;
	}
}

int	control_mouse(int mousecode, int x, int y, t_fractol *f)
{
	if (mousecode == MOUSE_R_CLK)
	{
		f->fractal.shift++;
		if (f->fractal.shift > 2)
			f->fractal.shift = 0;
	}
	if (mousecode == MOUSE_L_CLK)
		f->mouse.press = !f->mouse.press;
	mouse_wheel(mousecode, x, y, f);
	draw_fractal(f);
	return (0);
}

int	control_julia(int x, int y, t_fractol *f)
{
	if (f->mouse.press == 1 && f->fractal.type == 1)
	{
		f->fractal.cj = redefine(4 * ((double) x / WIDTH - 0.5), \
						4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(f);
	}
	return (0);
}
