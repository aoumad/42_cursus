/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/12 16:25:08 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_zoom(int mousecode, int *x, int *y, t_param *param)
{
	double	zoom;
	double	r_pos;
	double	i_pos;

	if (mousecode == WHEEL_DOWN)
		zoom = 0.833;
	if (mousecode == WHEEL_UP)
		zoom = 1.2;
	r_pos = param->zoom.min_real + (double) *x / (WIDTH)
		* (param->zoom.max_real - param->zoom.min_real);
	i_pos = param->zoom.max_imag - (double) *y / (HEIGHT)
		* (param->zoom.max_imag - param->zoom.min_imag);
	param->zoom.max_real = (param->zoom.max_real - r_pos) * zoom + r_pos;
	param->zoom.min_real = (param->zoom.min_real - r_pos) * zoom + r_pos;
	param->zoom.max_imag = (param->zoom.max_imag - i_pos) * zoom + i_pos;
	param->zoom.min_imag = (param->zoom.min_imag - i_pos) * zoom + i_pos;
	draw_fractol(param);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

double	atod(char *str, int *error)
{
	int		sign;
	double	result;
	int		i;
	double	j;

	sign = 1;
	result = 0;
	j = 0;
	i = 0;
	sign = ft_inputcheck(str, error);
	while (ft_isspace (str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
		j++;
	}
	return ((result * pow(0.1, j)) * sign);
}

void	set_w_size(t_param **param, t_complex *scale)
{
	scale->real = ((*param)->zoom.max_real - (*param)->zoom.min_real) / WIDTH;
	scale->imag = ((*param)->zoom.max_imag - (*param)->zoom.min_imag) / HEIGHT;
}
