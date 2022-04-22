/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:13 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/21 18:42:48 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    fractol_inits(int argc, char **argv)
{
    t_param param;
    int     limit;
    
    param.max_iter = 20;
    param.color_shift = 0;
    param.zoom.max_real = 2;
    param.zoom.max_imag = 2;
    param.zoom.min_real = -2;
    param.zoom.min_imag = -2;
    read_input(argc, argv, &param);
    param.mlx = mlx_init();
    param.win = mlx_new_window(param.mlx, WIDTH, HEIGHT, "Fractol");
    param.img = mlx_new_image(param.mlx, WIDTH, HEIGHT);
    param.im_adresse = mlx_get_data_addr(); //to get information related to the image
    draw_fractol(&param, limit);
    
}