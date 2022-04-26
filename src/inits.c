/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:13 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/26 17:58:36 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_mlx_pixel_put(t_param *param, int x, int y, int color)
{
    char    *dest;

    dest = param->im_adresse + (y * param->size_line + x * (param->bpp / 8));
    *(unsigned int *)dest = color;
}

void    fractol_inits(int argc, char **argv)
{
    t_param param;
    int     limit;
    
    param.max_iter = 100;
    param.zoom.max_real = 2;
    param.zoom.max_imag = 2;
    param.zoom.min_real = -2;
    param.zoom.min_imag = -2;
    read_input(argc, argv, &param);
    param.mlx = mlx_init();
    param.win = mlx_new_window(param.mlx, WIDTH, WIDTH, "Fractol");
    param.img = mlx_new_image(param.mlx, WIDTH, WIDTH);
    param.im_adresse = mlx_get_data_addr(param.img, &(param.bpp),
            &(param.size_line), &(param.endian));
                    //to get information related to the image
    draw_fractol(&param, limit);
    mlx_mouse_hook(param.win, mouse_hook, &param);
    mlx_hook(param.win, DESTROY_NOTIFY, 0, &ft_exit, &param);
    mlx_key_hook(param.win, &key_actions, &param);
    mlx_loop(param.mlx);
    exit (0);
}