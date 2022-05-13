/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/13 12:53:38 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_complex c, int limit)
{
	int					iter;
	register t_complex	z;
	register t_complex	tmp;

	z.real = c.real;
	z.imag = c.imag;
	tmp.real = z.real * z.real;
	tmp.imag = z.imag * z.imag;
	iter = 0;
	while ((tmp.real + tmp.imag <= 4) && iter < limit)
	{
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp.real - tmp.imag + c.real;
		tmp.real = z.real * z.real;
		tmp.imag = z.imag * z.imag;
		iter++;
	}
	return (iter);
}

int	julia(t_complex c, int limit, t_param *param)
{
	int					iter;
	register t_complex	z;
	register t_complex	tmp;

	z.real = c.real;
	z.imag = c.imag;
	tmp.real = z.real * z.real;
	tmp.imag = z.imag * z.imag;
	iter = 0;
	while ((tmp.real + tmp.imag <= 4) && iter < limit)
	{
		z.imag = 2 * z.real * z.imag + param->julia.imag;
		z.real = tmp.real - tmp.imag + param->julia.real;
		tmp.real = z.real * z.real;
		tmp.imag = z.imag * z.imag;
		iter++;
	}
	return (iter);
}

int	burning_ship(t_complex c, int limit)
{
	int					iter;
	register t_complex	z;
	register t_complex	tmp;

	z.real = c.real;
	z.imag = c.imag;
	tmp.real = z.real * z.real;
	tmp.imag = z.imag * z.imag;
	iter = 0;
	while ((tmp.real + tmp.imag <= 4) && iter < limit)
	{
		z.imag = -2 * fabsl(z.real * z.imag) + c.imag;
		z.real = tmp.real - tmp.imag + c.real;
		tmp.real = z.real * z.real;
		tmp.imag = z.imag * z.imag;
		iter++;
	}
	return (iter);
}

int	draw_second(t_complex parts, t_param *param)
{
	int	loop_count;
	int	color;

	color = 0;
	if (param->fractl_type == JULIA)
		loop_count = julia(parts, param->max_iter, param);
	else if (param->fractl_type == BURNINGSHIP)
		loop_count = burning_ship(parts, param->max_iter);
	else
		loop_count = mandelbrot(parts, param->max_iter);
	if (loop_count == param->max_iter)
		color = 0;
	else
		color = (param->color * loop_count);
	my_mlx_pixel_put(param, param->x, param->y, color);
	return (0);
}

void	draw_fractol(t_param *param)
{
	int			loop_count;
	t_complex	parts;
	t_complex	scale;

	loop_count = 0;
	set_w_size(&param, &scale);
	param->y = 0;
	while (param->y < HEIGHT)
	{
		parts.imag = param->zoom.max_imag - param->y * scale.imag;
		param->x = 0;
		while (param->x < WIDTH)
		{
			parts.real = param->zoom.min_real + param->x * scale.real;
			draw_second(parts, param);
			param->x++;
		}
		param->y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
