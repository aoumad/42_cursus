/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/13 12:49:36 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

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
# define M 46
# define L 37
# define S 1
# define D 2
# define RAND 15
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
}	t_complex;

typedef struct s_param{
	void		*mlx;
	void		*win;
	void		*img;
	long double	zoom_factor;
	int			x;
	int			y;
	int			endian;
	int			color;
	int			fractl_type;
	int			bpp;
	int			stop;
	int			size_line;
	char		*im_adrss;
	int			iter;
	int			max_iter;
	t_complex	julia;
	t_complex	zoom;
}	t_param;

//=========== FRACTOL INITS=======//
//int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_param *paramaters, int x, int y, int color);
void		fractol_inits(int argc, char **argv);

//=========== HELPER FUNCTIONS=======//
double		atod(char *str, int *error);
void		set_zoom(int mousecode, int *x, int *y, t_param *param);
void		set_w_size(t_param **param, t_complex *scale);

//===========FRACTALS=======//
int			mandelbrot(t_complex c, int limit);
int			julia(t_complex c, int limit, t_param *parameters);
void		draw_fractol(t_param *param);
void		set_color(t_param *param);
void		rand_color(t_param *vars);
int			draw_second(t_complex parts, t_param *param);

//===========KEY HOOKS=======//

int			ft_close(int key, t_param *parameters);
int			ft_exit(void);
int			mouse_hook(int mousecode, int x, int y, t_param *param);
int			key_actions(int key, t_param *param);
int			mouse_move(int x, int y, t_param *param);

//===========INPUT CHECK=======//

int			ft_inputcheck(char *str, int *error);
int			read_input(int argc, char **argv, t_param *param);
void		ft_error(void);

//==========LIBFT=============//
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);

#endif
