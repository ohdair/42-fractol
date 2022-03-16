/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:32:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/16 20:09:47 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usagekeys.h"
#include "fractol.h"

void	more_key_control(int keycode, t_fractol *f)
{
	if (keycode == KEY_ENTER && f-> fractal.type == 0)
	{
		f->fractal.type = f->info.select + 1;
		if (f->fractal.type == 3)
		{
			reset_background(f);
			init_fern_fractal(f);
		}
		if (f->fractal.type == 2)
		{
			initialize_limits(f);
			f->formula = &mandelbrot;
		}
		if (f->fractal.type == 1)
		{
			initialize_limits(f);
			f->formula = &julia;
		}
	}
	if (keycode == KEY_BACKSPACE && f->fractal.type)
	{
		mlx_clear_window(f->mlx.init, f->mlx.win);
		f->fractal.type = 0;
	}
}

void	move_fractal(int keycode, t_fractol *f)
{
	if (f->fractal.type == 1 || f->fractal.type == 2)
	{
		if (keycode == KEY_UP)
			f->fractal.center.im += 0.1 * f->fractal.ratio;
		else if (keycode == KEY_DOWN)
			f->fractal.center.im -= 0.1 * f->fractal.ratio;
		else if (keycode == KEY_LEFT)
			f->fractal.center.re += 0.1 * f->fractal.ratio;
		else if (keycode == KEY_RIGHT)
			f->fractal.center.re -= 0.1 * f->fractal.ratio;
	}
}

int	control_keys(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_R)
		rand_color(f);
	if (keycode == KEY_S && f->fractal.type == 0)
	{
		f->info.select++;
		if (f->info.select > 2)
			f->info.select = 0;
		add_info_menu(f);
	}
	if (keycode == KEY_W && f->fractal.type == 0)
	{
		f->info.select--;
		if (f->info.select < 0)
			f->info.select = 2;
		add_info_menu(f);
	}
	more_key_control(keycode, f);
	move_fractal(keycode, f);
	return (0);
}
