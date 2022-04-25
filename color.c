/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/25 06:01:47 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_color(t_param *param)
{
    my_mlx_pixel_put(param->mlx, param->win, param->x, param->y, (int)0x40916c);
}

void	rand_color(t_param *vars)
{
	if (vars->color == 0x124500)
		vars->color = 0xff0600;
	else if (vars->color == 0xff0600)
		vars->color = 0x050000;
	else if (vars->color == 0x050000)
		vars->color = 0xcbcfd3;
	else if (vars->color == 0xcbcfd3)
		vars->color = 0xf9fbff;
	else if (vars->color == 0xf9fbff)
		vars->color = 0x85143;
	else if (vars->color == 0x85143)
		vars->color = 0x124500;
	else if (vars->color == 0x124500)
		vars->color = 0x40916c;
}