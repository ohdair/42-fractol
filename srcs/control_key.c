/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:32:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/15 16:38:55 by jaewpark         ###   ########.fr       */
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
			init_fern_fractal(f);
		if (f->fractal.type == 2 || f->fractal.type == 1)
			initialize_limits(f);
	}
	if (keycode == KEY_BACKSPACE && f->fractal.type)
	{
		mlx_clear_window(f->mlx.init, f->mlx.win);
		f->fractal.type = 0;
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
	return (0);
}
