/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:06 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/25 06:08:01 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(t_complex c, int limit)
{
    int iter;
    t_complex   z;
    t_complex   tmp;

    z.real = c.real;
    z.imag = c.imag;
    tmp.real = z.real * z.real;
    tmp.imag = z.imag * z.imag;
    iter = 0;
    while ((tmp.real + tmp.imag <= 4) && iter < limit)
    {
        z.imag = 2 * z.imag * z.real + c.imag;
        z.real = tmp.real - tmp.imag + c.real;
        tmp.real = z.real * z.real;
        tmp.imag = z.imag * z.imag;
        iter++;
    }
    return (iter);
}

int julia(t_complex c, int limit, t_param *param)
{
    int         iter;
    t_complex   z;
    t_complex   tmp;
    
    z.real = c.real;
    z.imag = c.imag;
    tmp.real = z.real * z.real;
    tmp.imag = z.imag * z.imag;
    iter = 0;
    while ((tmp.real + tmp.imag <= 4) && iter < limit)
    {
        z.imag = 2 * z.imag * z.real + param->julia.imag;
        z.real = tmp.real - tmp.imag + param->julia.real;
        tmp.real = z.real * z.real;
        tmp.imag = z.imag * z.imag;
        iter++;
    }
    return (iter);
}

void    draw_fractol(t_param *param, int limit)
{
    int         loop_count;
    t_complex   parts;
    t_complex   scale;
    
    set_size(&param, &scale);
    param->y = 0;
    while (param->y < WIDTH)
    {
        parts.imag = param->zoom.max_imag - param->y * scale.imag;
        param->x = 0;
        while (param->x < WIDTH)
        {
            parts.real = param->zoom.min_imag + param->x * scale.real;
            if (param->fractal_type == JULIA)
                loop_count = julia(parts, param->max_iter, param);
            else
                loop_count = mandelbrot(parts, param->max_iter);
            set_color(param);
            param->x++;
        }
        param->y++;
    }
    mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}