/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/12 16:17:59 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	rand_color(t_param *param)
{
	if (param->color == 0x124500)
		param->color = 0xff0600;
	else if (param->color == 0xff0600)
		param->color = 0x050000;
	else if (param->color == 0x050000)
		param->color = 0xcbcfd3;
	else if (param->color == 0xcbcfd3)
		param->color = 0xf9fbff;
	else if (param->color == 0xf9fbff)
		param->color = 0x85143;
	else if (param->color == 0x85143)
		param->color = 0x124500;
	else
		param->color = 0x40916c;
}
