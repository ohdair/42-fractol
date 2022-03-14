/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:35:30 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/14 16:53:50 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractol	*f;

	f = (t_fractol *)malloc(sizeof(t_fractol));
	if (!f)
		write(1, "Memory Allocation failed", 24);
	f->fractal.type = 0;
	f->mlx.init = mlx_init();
	f->mlx.win = mlx_new_window(f->mlx.init, WIN_WIDTH, \
			WIN_HEIGHT, "Fract-ol");
	f->mlx.img = mlx_new_image(f->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	f->image.addr = mlx_get_data_addr(f->mlx.img, &f->image.bits, \
			&f->image.size, &f->image.endian);
	mlx_hook(f->mlx.win, 2, 0, control_keys, f);
	mlx_hook(f->mlx.win, 4, 0, control_mouse, f);
	mlx_loop_hook(f->mlx.init, render_next_frame, f);
	mlx_loop(f->mlx.init);
	return (0);
}
