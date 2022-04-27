/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:28:13 by kali              #+#    #+#             */
/*   Updated: 2022/04/26 18:29:08 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MANDELBROT 1
# define BURNINGSHIP 3
# define JULIA 2
# define ERROR -1

# define ESC 53
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123
# define SPACE 49
# define WHEEL_DOWN 4
# define WHEEL_UP 5
# define MAGENTA "\e[35m"
# define BLUE  "\e[32m"
# define LIGHTYELLOW "\e[93m"
# define RED  "\e[92m"
# define RESET  "\e[0m"

typedef struct s_complex{
	long double	real;
	long double	max_real;
	long double	min_real;
	long double	max_imag;
	long double	min_imag;
	long double	imag;
	long double	iter;
}t_complex;

typedef struct s_param{
	void		*mlx;
	void		*win;
	void		*img;
	long double	zoom_factor;
	int			x;
	int			y;
	int			endian;
	uint8_t		*color_scheme;
	int			color_shift;
	int			fractl_type;
	int			bpp;
	int			size_line;
	char		*im_adrss;
	size_t		iter;
	size_t		max_iter;
	t_complex	julia;
	t_complex	zoom;
}t_param;

//=========== FRACTOL INITS=======//
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_param *paramaters, int x, int y, int color);
void		fractol_inits(int argc, char **argv);

//=========== HELPER FUNCTIONS=======//
double		atod(char *str, int *error);
void		set_zoom(int mousecode, int *x, int *y, t_param *param);
void		set_w_size(t_param **param, t_complex *scale);

//===========FRACTALS=======//
int			mandelbrot(t_complex c, int limit);
int			julia(t_complex c, int limit, t_param *parameters);
void		draw_fractol(t_param *parameter, int limit);
void		set_color(int loop_count, int limit, t_param *param);
void		color_array(t_param *frctl);
void		color_shift(t_param *frctl);

//===========KEY HOOKS=======//

int			ft_close(int key, t_param *parameters);
int			ft_exit(t_param *param);
int			mouse_hook(int mousecode, int x, int y, t_param *param);
int			key_actions(int key, t_param *param, t_complex *frctl);

//===========INPUT CHECK=======//

int			ft_inputcheck(char *str, int *error);
int			read_input(int argc, char **argv, t_param *param);
void		ft_error(int argc, char **argv);

#endif