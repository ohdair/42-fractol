/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:05:41 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/17 18:13:58 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coordinate	redefine(double re, double im)
{
	t_coordinate	tmp;

	tmp.re = re;
	tmp.im = im;
	return (tmp);
}

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->image.addr + (y * f->image.size + x * (f->image.bits / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_fractol *f)
{
	if (f->fractal.type == 0)
		add_info_menu(f);
	if (f->fractal.type == 1 || f->fractal.type == 2)
	{
		mlx_clear_window(f->mlx.init, f->mlx.win);
		if (f->fractal.type == 1)
			mlx_hook(f->mlx.win, 6, 0, control_julia, f);
		draw_fractal(f);
	}
	if (f->fractal.type == 3)
	{
		mlx_clear_window(f->mlx.init, f->mlx.win);
		fern_fractal(f);
		mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->mlx.img, 0, 0);
	}
	return (0);
}
