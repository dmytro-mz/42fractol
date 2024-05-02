/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:58:41 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/02 11:11:41 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_help(void)
{
	ft_putendl_fd("Usage:", STDOUT_FILENO);
	ft_putendl_fd("fractol <fractal type> "
		"[<real value> <imaginary value>]", STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	ft_putendl_fd("Example:", STDOUT_FILENO);
	ft_putendl_fd("fractol J - 0 5251993 - 0 5251993", STDOUT_FILENO);
	ft_putendl_fd("fractol J + 0 4 + 0 6", STDOUT_FILENO);
	ft_putendl_fd("fractol M", STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	ft_putendl_fd("Fractal types:", STDOUT_FILENO);
	ft_putendl_fd("  Julia - \"J\"", STDOUT_FILENO);
	ft_putendl_fd("  Mandelbrot - \"M\"", STDOUT_FILENO);
	ft_putendl_fd("  Burning Shape - \"B\"", STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	ft_putendl_fd("Julia fractal type needs parameter which is a "
		"complex number", STDOUT_FILENO);
	ft_putendl_fd("Please provide real and imaginary parts as "
		"<sign> <int part> <decimal part>", STDOUT_FILENO);
	exit(0);
}
