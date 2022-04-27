/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 04:41:17 by kali              #+#    #+#             */
/*   Updated: 2022/04/24 17:42:40 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_param *param, int x, int y, int color)
{
	char	*dest;

	dest = param->im_adrss + (y * param->size_line + x * (param->bpp / 8));
	*(unsigned int *)dest = color;
}

void	fractol_inits(int argc, char **argv)
{
	t_param	param;
	int		limit;

	param.max_iter = 20;
	param.color_shift = 0;
	param.zoom.max_real = 2;
	param.zoom.max_imag = 2;
	param.zoom.min_real = -2;
	param.zoom.min_imag = -2;
	read_input(argc, argv, &param);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, WIDTH, HEIGHT, "Fractol!");
	param.img = mlx_new_image(param.mlx, WIDTH, HEIGHT);
	param.im_adrss = mlx_get_data_addr(param.img, &(param.bpp),
			&(param.size_line), &(param.endian));
	draw_fractol(&param, limit);
	mlx_mouse_hook(param.win, mouse_hook, &param);
	mlx_hook(param.win, 17, 0, &ft_exit, &param);
	mlx_key_hook(param.win, &key_actions, &param);
	mlx_loop(param.mlx);
	exit (0);
}
