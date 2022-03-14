/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:51:12 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/11 19:25:11 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	add_info_menu(t_fractol *f)
{
	int		img_w;
	int		img_h;

	f->info.title = mlx_xpm_file_to_image(f->mlx.init, "./img/fr.xpm", \
						&img_w, &img_h);
	f->info.ju = mlx_xpm_file_to_image(f->mlx.init, "./img/ju1.xpm", \
						&img_w, &img_h);
	f->info.ma = mlx_xpm_file_to_image(f->mlx.init, "./img/ma1.xpm", \
						&img_w, &img_h);
	f->info.fe = mlx_xpm_file_to_image(f->mlx.init, "./img/ja1.xpm", \
						&img_w, &img_h);
	select_info_menu(f);	
	mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->info.title, 250, 0);
	mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->info.ju, 125, 0);
	mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->info.ma, 300, 0);
	mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->info.fe, 250, 0);
}

void	select_info_menu(t_fractol *f)
{
	int		img_w;
	int		img_h;

	if (f->info.select == 0)
		f->info.ju = mlx_xpm_file_to_image(f->mlx.init, "./img/ju2.xpm", \
						&img_w, &img_h);
	if (f->info.select == 1)
		f->info.ma = mlx_xpm_file_to_image(f->mlx.init, \
						"./img/ma2.xpm", &img_w, &img_h);
	if (f->info.select == 2)
		f->info.fe = mlx_xpm_file_to_image(f->mlx.init, "./img/ja2.xpm", \
						&img_w, &img_h);
}