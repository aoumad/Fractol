/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:11 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/26 18:25:17 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_zoom(int mouse_code, int *x, int *y, t_param *param)
{
    double  zoom;
    double  r_pos;
    double  i_pos;
    int limit;
    
    if (mouse_code == WHEEL_UP)
        zoom = 1.2;
    if (mouse_code == WHEEL_DOWN)
        zoom = 0.833;
    draw_fractol(param, limit);
}

int ft_isspace(char c)
{
    if (c == ' ' || c == '\f' || c == '\v' || c == '\r' || c == '\n'
        || c == '\t')
        return (1);
    return (0);
}

double  atod(char *str, int *error)
{
    int     sign;
    double  result;
    int     i;
    int     j;
    
    sign = 1;
    result = 0;
    i = 0;
    j = 0;
    sign = ft_inputcheck(str, error);
    while (ft_isspace (str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (ft_isdigit(str[i]))
        result = result * 10 + (str[i++] - '0');
    if (str[i] == '.')
        i++;
    while (ft_isdigit(str[i]))
    {
        result = result * 10 + (str[i++] - '0');
        j++;
    }
    return ((result * pow(0.1, j)) * sign);
}

void    set_size(t_param **param, t_complex *scale)
{
    scale->real = ((*param)->zoom.max_real - (*param)->zoom.min_real) / WIDTH;
    scale->imag = ((*param)->zoom.max_imag - (*param)->zoom.min_imag) / WIDTH;
}