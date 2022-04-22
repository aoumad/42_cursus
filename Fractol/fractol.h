/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:08 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/20 18:50:42 by aoumad           ###   ########.fr       */
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
# define HEIGHT 250
# define MANDELBROT 1
# define JULIA 2
# define ERROR -1
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
    uint8_t     *color_scheme;
    int         color_shift;
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
//void    set_color()

//  === LIBFT ===//
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

//  === INPUT CHECK ===/
int read_input(int argc, char **argv, t_param *param);


#endif