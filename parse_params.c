/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:57:15 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/01 20:57:15 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		is_numeric(char *str);
double	parse_double(char *str_sign, char *str_int, char *str_dec);

void	parse_params(int ac, char **av, t_state *state)
{
	if (ac < 2)
		show_help();
	if (
		ac == 8
		&& !ft_memcmp(av[1], "J", 2)
		&& (!ft_memcmp(av[2], "+", 2) || !ft_memcmp(av[2], "-", 2))
		&& is_numeric(av[3])
		&& is_numeric(av[4])
		&& (!ft_memcmp(av[5], "+", 2) || !ft_memcmp(av[5], "-", 2))
		&& is_numeric(av[6])
		&& is_numeric(av[7])
	)
	{
		state->fract_func_ptr = julia;
		state->c.x = parse_double(av[2], av[3], av[4]);
		state->c.y = parse_double(av[5], av[6], av[7]);
	}
	else if (!ft_memcmp(av[1], "M", 2))
		state->fract_func_ptr = mandelbrot;
	else if (!ft_memcmp(av[1], "B", 2))
		state->fract_func_ptr = burning_ship;
	else
		show_help();
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

double	parse_double(char *str_sign, char *str_int, char *str_dec)
{
	int		sign;
	double	decimal;

	sign = (str_sign[0] == '+') * 2 - 1;
	decimal = (double)ft_atoi(str_dec) / pow(10, ft_strlen(str_dec));
	return (sign * (ft_atoi(str_int) + decimal));
}
