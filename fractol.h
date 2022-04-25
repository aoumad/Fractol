/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:08 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/24 23:34:35 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 250
//# define HEIGHT 250
# define MANDELBROT 1
# define JULIA 2
# define ERROR -1

# define ESC 53
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123
# define SPACE 49
# define RAND 15
# define A_KEY 0

# define EXPOSE 12
# define MOTION_NOTIFY 6
# define KEYPRESS 2
# define DESTROY_NOTIFY 17

# define WHEEL_DOWN 4
# define WHEEL_UP 5
# define MAGENTA "\e[35m"
# define BLUE  "\e[32m"
# define LIGHTYELLOW "\e[93m"
# define RED  "\e[92m"
# define RESET  "\e[0m"

typedef struct s_complex
{
    long double real;
    long double max_real;
    long double min_real;
    long double imag;
    long double max_imag;
    long double min_imag;
    long double iter;
}   t_complex;

typedef struct s_param
{
    void        *mlx;
    void        *win;
    void        *img;
    long double zoom_factor;
    int         x;
    int         y;
    int         endian;
    int         color;
    int         fractal_type;
    int         bpp;
    int         size_line;
    int         *im_adresse;
    size_t      iter;
    size_t      max_iter;
    t_complex   julia;
    t_complex   zoom;
}   t_param;

//  === FRACTOL INITS ===//
void    fractol_inits(int argc, char **argv);
void    my_mlx_pixel_put();

//  === FRACTALS ===//
int mandelbrot(t_complex c, int limit);
int julia(t_complex c, int limit, t_param *parameters);
void    draw_fractol(t_param *parameter, int limit);

//  === LIBFT ===//
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
int	ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);

//  === INPUT CHECK ===//
int         read_input(int argc, char **argv, t_param *param);
static int  input_check_rules(int sign_amount, int comma, char *str, int i);
int         ft_inputcheck(char *str, int *error);
void        help_user(void);

//  === KEY HOOKS ===//
int ft_close(int key, t_param *param);
int ft_exit(t_param *param);
int mouse_hook(int mouse_code, int x, int y, t_param *param);
int key_actions(int key, t_param *param, t_complex *fract);

//  === Color === /
void	rand_color(t_param *vars);
void    set_color(t_param *param);
#endif