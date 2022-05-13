/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/13 21:41:25 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_param *param, int x, int y, int color)
{
	char	*dest;

	dest = param->im_adrss + (y * param->size_line + x * (param->bpp / 8));
	*(unsigned int *)dest = color;
}

void	fractol_inits(int argc, char **argv)
{
	t_param	param;

	param.max_iter = 50;
	param.color = 0x124500;
	param.stop = 0;
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
	draw_fractol(&param);
	mlx_mouse_hook(param.win, mouse_hook, &param);
	mlx_hook(param.win, 6, 0, mouse_move, &param);
	mlx_hook(param.win, 17, 0, &ft_exit, &param);
	mlx_key_hook(param.win, &key_actions, &param);
	mlx_loop(param.mlx);
	exit (0);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}
