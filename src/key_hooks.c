/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:32:05 by kali              #+#    #+#             */
/*   Updated: 2022/02/17 20:39:33 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int key, t_param *parameters)
{
	if (key == ESC)
	{
		mlx_destroy_window(parameters->mlx, parameters->win);
		exit (0);
	}
	return (0);
}

int	ft_exit(t_param *param)
{
	exit (0);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_param *param)
{
	if (mousecode == WHEEL_UP || mousecode == WHEEL_DOWN)
		set_zoom(mousecode, &x, &y, param);
	return (0);
}

int	key_actions(int key, t_param *param, t_complex *fractl)
{
	int		limit;

	if (key == ESC)
		ft_close(key, param);
	if (key == SPACE)
		color_shift(param);
	if (key == ARROW_UP)
		param->max_iter += 5;
	if (key == ARROW_DOWN)
		param->max_iter -= 5;
	draw_fractol(param, limit);
	return (0);
}
