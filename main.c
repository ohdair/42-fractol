/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:35:30 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/11 23:40:02 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	f_usage(void)
{
	int i;

	ft_putendl("\033[01;31m\n\u23B9");
	i = -1;
	while (i++ < 32)
		ft_putendl("\u23B4");
	ft_putendl("\u23B8\n\u23B9 \033[0m");
	ft_putendl("\033[07;37m   Fract-ol Menu               \033[0m");
	ft_putendl("\033[01;31m \u23B8\n\u23B9\033[0m");
	ft_putendl("\033[01;32m    ./fractol                   \033[0m");
	ft_putendl("\033[01;31m \u23B8\n\u23B9");
	i = -1;
	while (i++ < 32)
		ft_putendl("\u23B5");
	ft_putendl("\u23B8\n\033\n[0m");
	ft_putendl("\n\033[07;37m    Fractol Usage    \033[0m");
	ft_putendl("\033[01;36m   Keys  : [ESC]     -> Exit      \033[0m");
	ft_putendl("\033[01;36m   Keys  : [W, S]    -> Select      \033[0m");
	ft_putendl("\033[01;36m   Keys  : [Enter]   -> Show Fract-ol\033[0m");
	ft_putendl("\033[01;36m   Keys  : [SPACE]   -> Colorize  \033[0m");
	ft_putendl("\033[01;36m   Mouse : [SCROLL]  -> Zoom      \033[0m");
	ft_putendl("\033[01;36m   Mouse : [R-Click] -> Colorize \033[0m");
	ft_putendl("\033[01;36m   Mouse : [L-Click] -> Freeze / Activate \033[0m");
}

int	main(void)
{
	t_fractol	*f;

	f->fractal.type = 0;
	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
		ft_error("Memory Allocation failed", 1);
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