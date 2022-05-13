/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:16 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/12 16:29:49 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	input_check_rules(int sign_amount, int comma, char *str, int i)
{
	if (i > 16 || sign_amount > 1 || comma > 1 || str[i] != '\0')
		return (-1);
	if (sign_amount == 1 && str[0] != '+' && str[0] != '-')
		return (-1);
	else
		return (0);
}

int	ft_inputcheck(char *str, int *error)
{
	int		i;
	int		sign_amount;
	int		sign;
	int		comma;

	i = 0;
	comma = 0;
	sign = 1;
	sign_amount = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr("0123456789+-.", str[i]) == 0)
			break ;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1;
			sign_amount++;
		}
		if (str[i] == '.')
			comma++;
		i++;
	}
	*error = input_check_rules(sign_amount, comma, str, i);
	return (sign);
}

void	help_user(void)
{
	ft_putstr_fd("Unfortunately your input isnt valid\n", 1);
	ft_putstr_fd("Read the following instructions", 1);
	ft_putstr_fd("for a better understanding:\n", 1);
	ft_putstr_fd("\n"MAGENTA"_______________________________________\n", 1);
	ft_putstr_fd("[1] Enter the desired fractol type to output \n", 1);
	ft_putstr_fd(LIGHTYELLOW" [ mandelbrot ] [ julia ]\n", 1);
	ft_putstr_fd("\n"BLUE"Sample usage: ./fractol mandelbrot""\n", 1);
	ft_putstr_fd(MAGENTA, 1);
	ft_putstr_fd("\n""[2]For Julia Fractol select 2 starting values \n", 1);
	ft_putstr_fd(BLUE, 1);
	ft_putstr_fd("\n""Sample usage: ./fractol julia -0.8 -0.15 \n", 1);
	ft_putstr_fd(RESET"For more Julia sets check in file: julia.txt\n", 1);
	ft_putstr_fd(MAGENTA, 1);
	ft_putstr_fd("\n""[3] KEY CONTROLS \n", 1);
	ft_putstr_fd(RED"[ MOUSE WEEL ]"RESET"-> Controls Zoom \n", 1);
	ft_putstr_fd(RED"[ KEYS UP/DOWN ]"RESET"-> Controls Iterations \n", 1);
	ft_putstr_fd(RED"[ SPACE BAR ]"RESET"-> Controls Color Shift \n", 1);
	ft_putstr_fd("\n"MAGENTA"     ----- HAVE FUN!-----:)  \n", 1);
}

int	read_input(int argc, char **argv, t_param *param)
{
	int	error;

	error = 0;
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		param->julia.real = atod(argv[2], &error);
		param->julia.imag = atod(argv[3], &error);
		param->fractl_type = JULIA;
		if (error == ERROR)
			ft_error();
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12))
		param->fractl_type = BURNINGSHIP;
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		param->fractl_type = MANDELBROT;
	else
		ft_error();
	return (0);
}

void	ft_error(void)
{
	help_user();
	exit (ERROR);
}
