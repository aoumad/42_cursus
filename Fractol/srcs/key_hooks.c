/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:18 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/13 17:09:36 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_close(int key, t_param *param)
{
	if (key == ESC)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	return (0);
}

double	ft_map(double x, double s2, double e2)
{
	return (s2 + x * ((e2 - s2) / WIDTH));
}

int	mouse_move(int x, int y, t_param *param)
{
	if (x <= WIDTH && x <= HEIGHT && param->stop == 0)
	{
		param->julia.real = ft_map(x, -.4, 1.9);
		param->julia.imag = ft_map(y, -.4, 1.9);
		draw_fractol(param);
	}
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_param *param)
{
	if (mouse_code == WHEEL_DOWN || mouse_code == WHEEL_UP)
		set_zoom(mouse_code, &x, &y, param);
	return (0);
}

int	key_actions(int key, t_param *param)
{
	if (key == ESC)
		ft_close(key, param);
	else if (key == SPACE)
		rand_color(param);
	if (key == 1)
		param->stop = 1;
	if (key == 2)
		param->stop = 0;
	else if (key == M)
		param->max_iter += 5;
	else if (key == L)
		param->max_iter -= 5;
	else if (key == ARROW_UP)
		param->max_iter += 5;
	else if (key == ARROW_DOWN)
		param->max_iter -= 5;
	draw_fractol(param);
	return (0);
}
