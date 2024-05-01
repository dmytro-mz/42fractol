/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:51:14 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/01 20:51:14 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pixel_to_coordinate(int xy, double shift, int max, double zoom);

int	julia(int x, int y, t_state *s)
{
	int			i;
	t_complex	z;

	i = 0;
	z.x = pixel_to_coordinate(x, s->shift_x, WINDOW_HEIGHT, s->zoom);
	z.y = pixel_to_coordinate(y, s->shift_y, WINDOW_HEIGHT, s->zoom);
	while (c_mod(z) < ESCAPE_RADIUS && i < s->iter_tresh)
	{
		z = c_add(c_sqr(z), s->c);
		i++;
	}
	return (i);
}

int	mandelbrot(int x, int y, t_state *s)
{
	int			i;
	t_complex	z;

	i = 0;
	s->c.x = pixel_to_coordinate(x, s->shift_x, WINDOW_HEIGHT, s->zoom);
	s->c.y = pixel_to_coordinate(y, s->shift_y, WINDOW_HEIGHT, s->zoom);
	z.x = 0.0;
	z.y = 0.0;
	while (c_mod(z) < ESCAPE_RADIUS && i < s->iter_tresh)
	{
		z = c_add(c_sqr(z), s->c);
		i++;
	}
	return (i);
}

int	burning_ship(int x, int y, t_state *s)
{
	int			i;
	t_complex	z;

	i = 0;
	s->c.x = pixel_to_coordinate(x, s->shift_x, WINDOW_HEIGHT, s->zoom);
	s->c.y = pixel_to_coordinate(y, s->shift_y, WINDOW_HEIGHT, s->zoom);
	z.x = 0.0;
	z.y = 0.0;
	while (c_mod(z) < ESCAPE_RADIUS && i < s->iter_tresh)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		z = c_add(c_sqr(z), s->c);
		i++;
	}
	return (i);
}

double	pixel_to_coordinate(int xy, double shift, int max, double zoom)
{
	return ((2.0 * (xy + shift) / max - 1.0) * ESCAPE_RADIUS / zoom);
}
