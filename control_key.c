/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:32:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/11 17:32:49 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usagekeys.h"
#include "fractol.h"

int             control_keys(int keycode, t_fractol *f)
{
    if (keycode == KEY_ESC)
        exit(1);
    if (keycode == KEY_R || keycode == MOUSE_R_CLK)
        rand_color(f);
    if (keycode == MOUSE_UP)
        zoom_in((WIN_WIDTH / 2), (WIN_HEIGHT / 2), f);
    if (keycode == MOUSE_DOWN)
        zoom_out(f);
    
}