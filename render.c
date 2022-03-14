/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:05:41 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/11 23:40:02 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->image.addr + (y * f->image.size + x * (f->image.bits / 8));
	*(unsigned int *)dst = color;
}

int	 render_next_frame(t_fractol *f)
{
	if (f->fractal.type == 0)
		add_info_menu(f);
	if (f->fractal.type == 1 && f->fractal.type == 2)
	{
		if ()
	}


}