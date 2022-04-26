/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:18 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/26 18:36:55 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_close(int key, t_param *param)
{
    if (key == ESC)
    {
        mlx_destroy_window(param->mlx, param->win);
        exit(0);
    }
    return (0);
}

int ft_exit(t_param *param)
{
    exit(0);
    return (0);
}

int mouse_hook(int mouse_code, int x, int y, t_param *param)
{
    if (mouse_code == WHEEL_DOWN || mouse_code == WHEEL_UP)
        set_zoom(mouse_code, &x, &y, param);
    return (0);
}

int key_actions(int key, t_param *param, t_param *fract)
{
    int limit;

    if (key == ESC)
        ft_close(key, param);
    if (key == ARROW_UP)
        param->max_iter += 5;
    if (key == ARROW_DOWN)
        param->max_iter -= 5;
    if (key == RAND)
        rand_color(fract);
    draw_fractol(param, limit);
    return (0);
}